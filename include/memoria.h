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


    //caso as paginas já tenham sido concertidas
    //int escrita(int pagina);
    //	chamaria a função checklixo para ver em qual linha da cache fazer a escrita,
    //  se todas as linhas estiverem ocupadas, usamos o metodo de substituição.
    //int leitura(int pagina);
};

#endif
