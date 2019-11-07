#ifndef MEMORIA_H
#define MEMORIA_H

#include <vector>
#include <string>
using namespace std;

class Memoria{
  private:
    int tamMemoria;
    int tamFrame;
    vector<int> linhas;

  public:
    Memoria(int tamFrame);
    ~Memoria(); 

    string escrita(string pagina);
    string leitura(string pagina);
};

#endif