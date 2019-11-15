#include "algoritmosGeradorEnd.h"
#include <iostream>
#include <sstream>
#include <random>

using namespace std;

AlgoritmosSubstituicao::AlgoritmosSubstituicao(int tamMemoria, int tamPaginas,string metSubstituicao):
    tamMemoria(tamMemoria),tamPaginas(tamPaginas), metSubstituicao(metSubstituicao){
        totalPaginasNaMemoria = tamMemoria/tamPaginas;
    }

AlgoritmosSubstituicao::~AlgoritmosSubstituicao(){}

void AlgoritmosSubstituicao::substituir(string algoritmo, int pagina){
    

    if(algoritmo.compare("lru")){
        lru(pagina);
        return;
    }
    if(algoritmo.compare("fifo")){
        fifo(pagina);
        return;
    }     
    if(algoritmo.compare("nru")){
        nru(pagina);
        return;  
    }  
    if(algoritmo.compare("lfu")){
        fifo(pagina);
        return;
    } 
    if(algoritmo.compare("random")){
        random();
        return;
    } 
}

int AlgoritmosSubstituicao::random(){ 
    random_device rd;
	default_random_engine gen(rd());
	uniform_int_distribution<> dis(0,totalPaginasNaMemoria-1);
    return dis(gen);
}

int AlgoritmosSubstituicao::lru(int pagina){}

int AlgoritmosSubstituicao::fifo(int pagina){}

int AlgoritmosSubstituicao::nru(int pagina){}

int AlgoritmosSubstituicao::lfu(int pagina){}

bool AlgoritmosSubstituicao::checkLixo (int pagina){}
