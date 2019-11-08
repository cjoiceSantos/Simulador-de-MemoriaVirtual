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
    string metSubstituicao;  //

public:

    //na descrição do projeto, ao iniciar o programa, já é definido qual modelo de substituição será usado,
    //portanto, ele já pode ser passado como parâmetro no construtor.
    AlgoritmosSubstituicao(int totalPalavras, int totalPaginas, string metSubstituicao);  //
    ~AlgoritmosSubstituicao();

    int lru(string palavra);
    int fifo(string palavra);
    int nru(string palavra);
    int lfu(string palavra);
    int random();
    int converterHexaToDecimal(string palavra);
//  bool checkLixo (int pagina); -->para ver se a página contem lixo, caso haja apenas lixo, o programa pode 
//  só escrever, se nenhuma das páginas da cache tiver lixo, ai devemos começar a usar os metodos de substituição
};
#endif
