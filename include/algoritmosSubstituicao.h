#ifndef ALGORITMOSSUBSTITUICAO_H
#define ALGORITMOSSUBSTITUICAO_H

#include <vector>
#include <queue>
#include "string"
using namespace std;

class AlgoritmosSubstituicao{
private:    
    int totalPaginas;
    int totalPalavras;
    int palavraPorPagina;
    vector<int> frequencia;
    queue<int> fila;
    

public:

    AlgoritmosSubstituicao(int totalPalavras, int totalPaginas);
    ~AlgoritmosSubstituicao();

    int lru(string palavra);
    int fifo(string palavra);
    int nru(string palavra);
    int lfu(string palavra);
    int random();
    int converterHexaToDecimal(string palavra);
};
#endif