#ifndef ALGORITMOSGERACAOEND_H
#define ALGORITMOSGERACAOEND_H

#include <string>
#include <random>

using namespace std;

class AlgoritmosGeradorEnd{
    private:
	    int limite;
        int totalValores;
		random_device rd;
		default_random_engine gen;
		uniform_int_distribution<> dis;
        int valor;
		
	public:
		AlgoritmosGeradorEnd(int limite, int totalValores);
        ~AlgoritmosGeradorEnd();
		string converter(int dec);
		int gerar();
        void gerarArquivo();


};
#endif
