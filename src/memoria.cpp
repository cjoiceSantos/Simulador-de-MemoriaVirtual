#include "memoria.h"
#include <iostream>
#include <algorithm> 
#include <iterator> 
#include <random>

using namespace std;

set<int>::iterator it; 
set<int>::iterator aux;
map<int, int>::iterator paginaEscolhida;
int posicao; 

Memoria::Memoria(int tamMemoria, int tamFrame, string metSubstituicao): tamMemoria(tamMemoria), tamFrame(tamFrame), metSubstituicao(metSubstituicao){ 
    totalPaginasNaMemoria = tamMemoria/tamFrame;

    //criando uma matriz para o nru.
    if(metSubstituicao == "nru"){
        matrizNru = new int *[totalPaginasNaMemoria];
        for(campos = 0; campos < totalPaginasNaMemoria; campos++)
            matrizNru[campos] = new int[2];
        for(campos = 0; campos < totalPaginasNaMemoria; campos ++){ //para deixar os valores zerados. 
            matrizNru[campos][1] = 0;
        matrizNru[campos][2] = 0;
        }
    }	
}

Memoria::~Memoria(){}

int Memoria::escrita(int pagina){
    //verifico se a página ja está na memoria, te estiver não insere.
    if(leitura(pagina)){
        return 2; //página já está na memória
    }
    //verifico se há espaço para inserir
    if(frames.size() < totalPaginasNaMemoria){ 
        
	//==============================================================================
<<<<<<< HEAD
	if (metSubstituicao == "nru"){
	    //na escrita o nru altera os campos de referencia e escrita.
	    for(campos=0; campos<totalPaginasNaMemoria; campos ++){
=======
    //poderia tá em atualizar página?
        if (metSubstituicao == "nru"){
            //na escrita o nru altera os campos de referencia e escrita.
            for(campos=0; campos<totalPaginasNaMemoria; campos ++){
>>>>>>> 5d791e5d2b86b8381a830e594c70b787fa37e885
                if(matrizNru[campos][0] == pagina){
                    matrizNru[campos][1] = 1;
                    matrizNru[campos][2] = 1;
                }
            }
        } 
        //==============================================================================
            
        frames.insert(pagina);
        atualizarEstruturas(pagina);
        return 1; //página inserida 
    }
    
    //Se não há mais espaço, substitui a página
    substituir(pagina);
    return 0; //uma página foi substituida
}

bool Memoria::leitura(int pagina){ 	
    it = frames.find(pagina);
    if(it != frames.end()){

 	//se for no nru==================================
        if (metSubstituicao == "nru"){
            for(campos=0; campos<totalPaginasNaMemoria; campos ++){
                if(matrizNru[campos][0] == pagina){
                matrizNru[campos][1] = 1;
                }
            } 		
        }
	//================================================
    
        return true;
    }
    //No simulador é feito a chamada da escrita para a página faltante ser escrita na memória
    return false;
}

void Memoria::random(int pagina){ 
    random_device rd;
	default_random_engine gen(rd());
	uniform_int_distribution<> dis(0,totalPaginasNaMemoria-1);
    //posição aleatoria na memória
    posicao = dis(gen);
    it = frames.begin();
    //Avanço o iterador fornecido ate enésimo elemento indicado pela posição aleatória sorteada
    advance(it, posicao); 
    //removo a pagina antiga sorteada
    frames.erase(it);
    //adiciono a nova página.
    frames.insert(pagina);
}

void Memoria::lru(int pagina){
    it = frames.find(ordemDeUso[0]);
    frames.erase(it);
    frames.insert(pagina);
    ordemDeUso.erase(ordemDeUso.begin());
    ordemDeUso.push_back(pagina);
}

void Memoria::fifo(int pagina){
    //verifico a página que tem que sair da fila
    int paginaaSair = fila.front();
    fila.pop(); //remove da fila
    //busco a página na memória e removo
    it = frames.find(paginaaSair);
    frames.erase(it);
    //insiro a nova página
    frames.insert(pagina);  
    fila.push(pagina); 
}

void Memoria::nru(int pagina){
    int aux = 0;
    for(campos=0; campos<totalPaginasNaMemoria; campos ++){
         if(matrizNru[campos][1] == 0 && matrizNru[campos][2] == 0){
              matrizNru[campos][0] = pagina;
	      matrizNru[campos][1] = 1;
	      aux = 1;
	 }
		 
    }
    if ((aux == 0)){
         for(campos=0; campos<totalPaginasNaMemoria; campos ++){
         	if(matrizNru[campos][1] == 0 && matrizNru[campos][2] == 1){
              	    matrizNru[campos][0] = pagina;
              	    matrizNru[campos][1] = 1;
              	    aux = 1;
         	}
    	}
    } 
}

void Memoria::lfu(int pagina){
    int menor;
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
        /*
        quando ocorre a falta de pagina no nru, ele zera todos os campos de 'referencia'
        os campos de 'escrita' nunca são zerados.*/
        for(campos=0; campos<totalPaginasNaMemoria; campos ++){ 
            matrizNru[campos][1] = 0;
        }
        nru(pagina);
    }
    if(!metSubstituicao.compare("lfu")){
        lfu(pagina);
    }
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
