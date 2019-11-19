#include "algoritmosGeradorEnd.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

AlgoritmosGeradorEnd::AlgoritmosGeradorEnd(int limite, int totalValores, string nomeArquivo):
	limite(limite), 
	totalValores(totalValores), 
	nomeArquivo(nomeArquivo), 
	rd(), gen(rd()), 
	dis(0, limite){
	valor = std::round(dis(gen));
}

AlgoritmosGeradorEnd::~AlgoritmosGeradorEnd(){}

string AlgoritmosGeradorEnd::converter(int dec){	
	int quoc = dec;
	int tamanho = 0;
	string resultado = " ";

    //  para ver o tamanho
	while(quoc > 0){
		quoc = quoc/16;
		tamanho++;
	}
	
	int *rest = new int[tamanho];	
	int aux = tamanho;
	quoc = dec;	
    //	operando
	while(quoc > 0){
		rest[aux] = dec%16;
		quoc = dec/16;

		aux --;
		dec=dec/16;
	}

    //	concatenando a string
	for(int i=1; i<tamanho+1; i++){
        string aux;
		switch(rest[i]){
			case 10:
				aux = "A";
				resultado += aux;
				break;
			case 11:
				aux = "B";
				resultado += aux;
				break;
			case 12:
				aux = "C";
				resultado += aux;
				break;
			case 13:
				aux = "D";
				resultado += aux;
				break;
			case 14:
				aux = "E";
				resultado += aux;
				break;
			case 15:
				aux = "F";
				resultado += aux;
				break;
				default:
					int j = rest[i];
					resultado += to_string(j);	
		}
    }
	return resultado;
}

int AlgoritmosGeradorEnd::gerar(){
	valor=std::round(dis(gen));
	return valor;
}

void AlgoritmosGeradorEnd::gerarArquivo(){
	//a saida vai ser jogada nesse File
	std::ofstream outFile;
	outFile.open("arquivos_Teste/" + nomeArquivo + ".txt", ios::out);

	std::string hexadecimal;	// valor hexadec q vai ser gerado	
	 
	for(int i = 0; i < totalValores ; i++){
		int valor = gerar();
		hexadecimal = converter(valor);
		outFile << hexadecimal ;
		outFile << " ";

		int aux = gerar();	//aux vai gerar um valor aleatorio para leitura ou escrita
		char wr;
			if (aux % 2 == 0){
				wr = 'W';
			}
			else {
				wr = 'R';
			}
		outFile << wr ;
		if (i != totalValores - 1)
			outFile << '\n';
	}

	outFile.close();
}

int main(int argc, char const *argv[])
{
	AlgoritmosGeradorEnd *algoritmosGeradorEnd = new AlgoritmosGeradorEnd(stoi(argv[1]), stoi(argv[2]), argv[3]);
	algoritmosGeradorEnd->gerarArquivo();
}
