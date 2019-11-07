#include "algoritmosSubstituicao.h"
#include <iostream>
#include <random>

using namespace std;

AlgoritmosSubstituicao::AlgoritmosSubstituicao(int totalPalavras, int totalPaginas):
    totalPalavras(totalPalavras),totalPaginas(totalPaginas){
        palavraPorPagina = totalPalavras/totalPaginas;
    }

AlgoritmosSubstituicao::~AlgoritmosSubstituicao(){}


int AlgoritmosSubstituicao::random(){ 
    random_device rd;
	default_random_engine gen(rd());
	uniform_int_distribution<> dis(0,totalPaginas-1);
    return dis(gen);
}

int  AlgoritmosSubstituicao::converterHexaToDecimal(string palavraHex){
    int valor;
    stringstream stream;
    stream << palavraHex;
    stream >> hex >> valor;
    return valor;
}

int AlgoritmosSubstituicao::lru(string palavra){}
int AlgoritmosSubstituicao::fifo(string palavra){}
int AlgoritmosSubstituicao::nru(string palavra){}
int AlgoritmosSubstituicao::lfu(string palavra){}