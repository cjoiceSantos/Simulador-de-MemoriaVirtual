#include "memoria.h"
#include <iostream>
#include <algorithm> 
#include <iterator> 

using namespace std;

set<int>::iterator it, aux;
int posicao; 

Memoria::Memoria(int tamMemoria, int tamFrame, string metSubstituicao): tamMemoria(tamMemoria), tamFrame(tamFrame), metSubstituicao(metSubstituicao){ 
    totalPaginasNaMemoria = tamMemoria/tamFrame;
}

Memoria::~Memoria(){}

//considerando o completamente associativo

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

int Memoria::getTotalPaginasNaMemoria(){
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
    advance(it, posicao); //função  advance avança o iterador fornecido ate enésimo elemento
    //removo a pagina antiga sorteada
    frames.erase(it);
    //adiciono a nova página.
    frames.insert(pagina);
}

int Memoria::lru(int pagina){}

int Memoria::fifo(int pagina){}

int Memoria::nru(int pagina){}

int Memoria::lfu(int pagina){}

void Memoria::atualizarEstruturas(int pagina){
    //atualiza a fila
   // fila.push(pagina);
    //atualiza a frequência
   // aux = frequencia.find(pagina)
    //frequencia.insert(pagina, aux++);
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
        lru(pagina);
    }
    if(!metSubstituicao.compare("lfu")){
        lru(pagina);
    }
}