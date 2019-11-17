#include "memoria.h"
#include <iostream>
#include <algorithm> 
#include <iterator> 
#include <random>

using namespace std;

set<int>::iterator it; 
set<int>::iterator aux;
int posicao; 

Memoria::Memoria(int tamMemoria, int tamFrame, string metSubstituicao): tamMemoria(tamMemoria), tamFrame(tamFrame), metSubstituicao(metSubstituicao){ 
    totalPaginasNaMemoria = tamMemoria/tamFrame;
}

Memoria::~Memoria(){}

int Memoria::escrita(int pagina){
    //verifico se a página ja está na memoria, te estiver não insere.
    if(leitura(pagina)){
        return 2;
    }
    if(frames.size() < totalPaginasNaMemoria){ // do 0 ate totalPaginasNaMemoria-1 
        frames.insert(pagina);
        atualizarEstruturas(pagina);
        return 1;
    }
    substituir(pagina);
    return 0; 
}

bool Memoria::leitura(int pagina){ 
    it = frames.find(pagina);
    if(it != frames.end()){
        return true;
    }
    return false;
}

int Memoria::getTamMemoria(){
    return tamMemoria;
}
int Memoria::getTamFrame() {
    return tamFrame;
}

int unsigned Memoria::getTotalPaginasNaMemoria(){
    return totalPaginasNaMemoria;
}

set<int> Memoria::getFrame(){
    return frames;
}

void Memoria::print(){ 
    for (int it : frames){
        cout << it << " "; 
    }
}

void Memoria::random(int pagina){ 
    random_device rd;
	default_random_engine gen(rd());
	uniform_int_distribution<> dis(0,totalPaginasNaMemoria-1);
    //posição aleatoria
    posicao = dis(gen);
    it = frames.begin();
    advance(it, posicao); //função  advance avança o iterador fornecido ate enésimo elemento indicado pela posição sorteada
    //removo a pagina antiga sorteada
    frames.erase(it);
    //adiciono a nova página.
    frames.insert(pagina);
}

int Memoria::lru(int pagina){
    set<int>::iterator it = frames.find(ordemDeUso[0]);
    frames.erase(it);
    frames.insert(pagina);
    ordemDeUso.erase(ordemDeUso.begin());
    ordemDeUso.push_back(pagina);
}

void Memoria::fifo(int pagina){
    //verifico a página que tem que sair da fila
    int paginaaSair = fila.front();
    fila.pop(); //remove da fila
    
    //busco a página na memória e remoro
    it = frames.find(paginaaSair);
    frames.erase(it);
    //insiro a nova página
    frames.insert(pagina);  
    fila.push(pagina); 
}


int Memoria::nru(int pagina){}

void Memoria::lfu(int pagina){
    int menor;
    map<int, int>::iterator paginaEscolhida;
    for (map<int, int>::iterator it = frequencia.begin(); it != frequencia.end(); it++){
        if (it == frequencia.begin()){
            menor = it->second;
            paginaEscolhida = it; 
        }
        else if (it->second < menor){
            menor = it->second;
            paginaEscolhida = it; 
        }          
    }

    // Acha a pagina que vai ser substituida
    set<int>::iterator frameEscolhido = frames.find(paginaEscolhida->first);

    // Apaga o frame antigo e adiciona o novo
    frames.erase(frameEscolhido);
    frames.insert(pagina);

    // Apaga a pagina antiga da frequencia e adiciana a nova
    frequencia.erase(paginaEscolhida);
    frequencia.insert(pair<int, int>(pagina, 1));  
}

void Memoria::atualizarEstruturas(int pagina){
    //atualiza a fila
    if (!metSubstituicao.compare("fifo"))
        fila.push(pagina);
    //busco no map, se não tem eu ensiro com inicial 1; 
  /*  aux = frames.find(pagina);
    if(aux == frames.end()){
        frequencia.insert(pagina, 1);
    }else{
         aux->second++;
    }*/
    // Atualiza a frequencia
    if (!metSubstituicao.compare("lfu")){
        map<int, int>::iterator it = frequencia.find(pagina);
        if (it != frequencia.end())
            frequencia[pagina] += 1;
        else
            frequencia.insert(pair<int, int> (pagina, 1));
    }
    else if (!metSubstituicao.compare("lru")){
        vector<int>::iterator it;
        for (it = ordemDeUso.begin(); it != ordemDeUso.end(); it++){
            if (*it == pagina){
                break;
            }
        }
        // Caso a pagina ainda não esteja no vector oredemDeUso
        if (it == ordemDeUso.end()){
            ordemDeUso.push_back(pagina);
        }
        else{ // Caso ja esteja, tem que ir pro final
            ordemDeUso.erase(it);
            ordemDeUso.push_back(pagina);
        }
    }
}

void Memoria::substituir(int pagina){
    if(!metSubstituicao.compare("random")){
        random(pagina);
    } 
    if(!metSubstituicao.compare("lru")){
        lru(pagina);
    }
    if(!metSubstituicao.compare("fifo")){
        fifo(pagina);
    }
    if(!metSubstituicao.compare("nru")){
        nru(pagina);
    }
    if(!metSubstituicao.compare("lfu")){
        lfu(pagina);
    }
}