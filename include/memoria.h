#ifndef MEMORIA_H
#define MEMORIA_H

#include <set>
using namespace std;

class Memoria{
  private:
    int tamMemoria;
    int tamFrame;
    int totalPaginasNaMemoria;
    set<int> frames; 

  public:
    Memoria(int tamMemoria, int tamFrame);
    ~Memoria(); 

    bool escrita(int pagina);
    bool leitura(int pagina);
    int getTamMemoria();
    int getTamFrame();
    int getTotalPaginasNaMemoria();
    set<int> getFrame();
    void print();
};

#endif