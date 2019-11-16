#ifndef MEMORIA_H
#define MEMORIA_H

#include <set>
#include <queue>
#include <map>
using namespace std;

class Memoria{
  private:
    int tamMemoria;
    int tamFrame;
    int totalPaginasNaMemoria;
    string metSubstituicao;
    set<int> frames;
    queue<int> fila;
    map<int,int> frequencia;
    
    int **matrizNru;
    int campos;
 

  public:
    Memoria(int tamMemoria, int tamFrame, string metSubstituicao);
    ~Memoria(); 

    int escrita(int pagina);
    bool leitura(int pagina);
    int getTamMemoria();
    int getTamFrame();
    int getTotalPaginasNaMemoria();
    set<int> getFrame();
    void print();
    void atualizarEstruturas(int pagina);
    void substituir(int pagina);
    int lru(int pagina);
    int fifo(int pagina);
    int nru(int pagina);
    int lfu(int pagina);
    void random(int pagina);

};
#endif
