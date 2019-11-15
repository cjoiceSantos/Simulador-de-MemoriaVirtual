#include <iostream>
#include <fstream>
#include <cstdlib>
#include <random>


#include "num.cpp"
#include "hexafunc.cpp"


int main(int argc, char const *argv[])
{
	//a saida vai ser jogada nesse File
	std::ofstream outFile;
	outFile.open("saida.txt", std::ios::out);


	std::string hexadecimal;	// valor hexadec q vai ser gerado	
	hexadec conversor;	// classe para converter
	num my_num(atoi(argv[1]));  //classe para gerar um num decimal aleatorio

	 
	for(int i=0; i<atoi(argv[2]) ; i++){
		int valor = my_num.gerar();
		hexadecimal=conversor.converter(valor);
		outFile << hexadecimal ;
		outFile << " ";

		int aux = my_num.gerar();	//aux vai gerar um valor aleatorio para leitura ou escrita
		char wr;
			if (aux%2 == 0){
				wr = 'W';
			}
			else {
				wr = 'R';
			}
		outFile << wr ;
		outFile << '\n';
	}

	outFile.close();

	return 0;
}
