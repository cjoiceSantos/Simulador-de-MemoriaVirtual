#include "algoritmosSubst.h"
#include <iostream>

using namespace std;

AlgoritmosSubstituicao::AlgoritmosSubstituicao(int totalFrames, int totalPaginas):
    totalFrames(totalFrames),totalPaginas(totalPaginas),rd(), gen(rd()), dis(1, totalFrames) {}

AlgoritmosSubstituicao::~AlgoritmosSubstituicao(){}

int AlgoritmosSubstituicao::lru(string palavra){}
int AlgoritmosSubstituicao::fifo(string palavra){}
int AlgoritmosSubstituicao::nru(string palavra){}
int AlgoritmosSubstituicao::lfu(string palavra){}


int AlgoritmosSubstituicao::random(){
    int value = round(dis(gen));
    
    cout << value <<endl;
    return value;
}