#include <sstream>
#include <iostream>
#include <string>
#include "hexafunc.h"


hexadec::hexadec(){}

std::string hexadec::converter(int dec){	

	int quoc = dec;
	int tamanho = 0;
	std::string resultado = " ";

//  para ver o tamanho
	while(quoc > 0){
		quoc = quoc/16;
		tamanho++;
	}
	
	int rest[tamanho];	
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
        std::string aux;
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
					resultado += std::to_string(j);
			
		}
    }






	return resultado;
}
