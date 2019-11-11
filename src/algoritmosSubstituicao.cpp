#include "algoritmosSubstituicao.h"
#include <iostream>
#include <sstream>
#include <random>

using namespace std;

AlgoritmosSubstituicao::AlgoritmosSubstituicao(int totalPalavras, int totalPaginas,string metSubstituicao):
    totalPalavras(totalPalavras),totalPaginas(totalPaginas), metSubstituicao(metSubstituicao){
        palavraPorPagina = totalPalavras/totalPaginas;
    }

AlgoritmosSubstituicao::~AlgoritmosSubstituicao(){}

void AlgoritmosSubstituicao::substituir(string algoritmo, int pagina){
    /*if(algoritmo.compare("lru")){
        lru(pagina);
        return ;
    }
    if(algoritmo.compare("fifo")){
        fifo(pagina);
        return "";
    }     
    if(algoritmo.compare("nru")){
        nru(pagina);
        return "";  
    }  
    if(algoritmo.compare("lfu")){
        fifo(pagina);
        return "";
    } 
    if(algoritmo.compare("random")){
        fifo(pagina);
        return "";
    } */
}

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

int AlgoritmosSubstituicao::lru(int pagina){}
int AlgoritmosSubstituicao::fifo(int pagina){}
int AlgoritmosSubstituicao::nru(int pagina){}
int AlgoritmosSubstituicao::lfu(int pagina){}
bool AlgoritmosSubstituicao::checkLixo (int pagina){}