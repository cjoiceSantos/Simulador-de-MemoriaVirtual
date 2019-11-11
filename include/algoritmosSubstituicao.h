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
    string metSubstituicao;
    vector<int> frequencia;
    queue<int> fila;
    

public:

    AlgoritmosSubstituicao(int totalPalavras, int totalPaginas,string metSubstituicao);
    ~AlgoritmosSubstituicao();

    void substituir(string algoritmo, int pagina);
    int lru(int pagina);
    int fifo(int pagina);
    int nru(int pagina);
    int lfu(int pagina);
    int random();
    int converterHexaToDecimal(string pagina);
    bool checkLixo (int pagina);
};
#endif