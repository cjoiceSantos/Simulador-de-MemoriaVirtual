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

bool Memoria::escrita(int pagina){
    if(frames.size() < totalPaginasNaMemoria){
        frames.insert(pagina);
        atualizarEstruturas(pagina);
        return true;
    }
    substituir(pagina);
    return false; 
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
    it = frames.begin();
    while(it!=frames.end()){
        cout << *it << " "; // *it no lugar de &it e um espaço para separar os itens
        it = frames.erase(it); // o iterador retornado pelo erase aqui é o próximo item do seu set
        //it++; -> não funciona quando está removendo o item durante a iteração, porque a remoção do item com o erase invalida o iterador corrente
    }
}

int Memoria::random(int pagina){ 
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
    fila.push(pagina);
    //atualiza a frequência
   // aux = frequencia.find(pagina)
    //frequencia.insert(pagina, aux++);
}

void Memoria::substituir(int pagina){
    if(metSubstituicao.compare("random")){
        random(pagina);
    } 
    if(metSubstituicao.compare("lru")){
        lru(pagina);
    }
    if(metSubstituicao.compare("fifo")){
        fifo(pagina);
    }
    if(metSubstituicao.compare("nru")){
        lru(pagina);
    }
    if(metSubstituicao.compare("lfu")){
        lru(pagina);
    }
}