#include "memoria.h"
#include <iostream>
#include <algorithm> 

using namespace std;

set<int>::iterator it;

Memoria::Memoria(int tamMemoria, int tamFrame): tamMemoria(tamMemoria), tamFrame(tamFrame){ 
    totalPaginasNaMemoria = tamMemoria/tamFrame;
}

Memoria::~Memoria(){}

//considerando o completamente associativo
bool Memoria::escrita(int pagina){
    if(frames.size() < totalPaginasNaMemoria){
        frames.insert(pagina);
        return true;
    }
    //vou chamar o metodo de substituir
    return false;
   
}

bool Memoria::leitura(int pagina){ 
    it = frames.find(pagina);
    if(it != frames.end()){
        return true;
    }
    escrita(pagina);
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