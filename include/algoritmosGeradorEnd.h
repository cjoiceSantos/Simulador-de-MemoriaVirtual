#ifndef ALGORITMOSGERACAOEND_H
#define ALGORITMOSGERACAOEND_H

#include <string>
#include <random>

using namespace std;

class AlgoritmosSubstituicao{
    private:
        int valor;
		random_device rd;
		default_random_engine gen;
		uniform_int_distribution<> dis;
        int totalValores;
        int limite;
	public:
		AlgoritmosSubstituicao(int limite, int totalValores);
        ~AlgoritmosSubstituicao();
		string converter(int dec);
		int gerar();
        void gerarArquivo();


};
#endif
