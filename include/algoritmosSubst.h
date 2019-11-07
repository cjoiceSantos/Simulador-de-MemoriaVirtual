#ifndef ALGORITMOSSUBSTITUICAO_H
#define ALGORITMOSSUBSTITUICAO_H

#include <vector>
#include <queue>
#include <random>
#include "string"
using namespace std;

class AlgoritmosSubstituicao{
private:    
    int totalPaginas;
    int totalFrames;
    int endPorPagina;
    vector<int> frequencia;
    queue<int> fila;

    //random
    random_device rd;
	default_random_engine gen;
	uniform_int_distribution<> dis;

public:

    AlgoritmosSubstituicao(int totalFrames, int totalPaginas);
    ~AlgoritmosSubstituicao();

    int lru(string palavra);
    int fifo(string palavra);
    int nru(string palavra);
    int lfu(string palavra);
    int random();
};
#endif