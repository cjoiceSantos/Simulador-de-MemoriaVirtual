#include <iostream>
#include "stdlib.h"
#include <fstream>
#include <sstream>
#include <string>
#include "memoria.h"
#include "algoritmosGeradorEnd.h"
using namespace std;

// Converte a palavra em hexadecimal para decimal
int  converterHexaToDecimal(string palavraHex){
    int valor;
    stringstream stream;
    stream << palavraHex;
    stream >> hex >> valor;
    return valor;
}

void gerarRelatorio(int tamMemoria, int tamPagina,string algoritmo, int totalPalavras, int paginasLidas,
int faltaPaginas, int paginasSujas, int paginasEscritas, int paginasRepetidas){
    cout << "___________________RELATÓRIO____________________ " << endl <<
            "TOTAL PAGINAS NA MEMÓRIA: " << tamMemoria/tamPagina << endl <<
            "ALGORITMO SUBSTITUIÇÃO: " << algoritmo << endl <<
            "PALAVRAS: " << totalPalavras << endl <<
            "TOTAL LEITURAS: " << paginasLidas+faltaPaginas << endl <<
            "  SUCESSO - " << paginasLidas << endl <<
            "  FALTA DE PÁGINA - " <<  faltaPaginas << endl <<
            "TOTAL ESCRITAS: " << paginasEscritas+paginasSujas << endl <<
            "  SUCESSO - " << paginasEscritas << endl << 
            "  REPETIÇÃO - " << paginasRepetidas << endl <<
            "  SUBSTITUIDAS - " << paginasSujas << endl;
}


int main(int argc, char const *argv[])
{   
   // AlgoritmosGeradorEnd gerando_arquivo(1000, 1000);
    //gerando_arquivo.gerarArquivo();

    //VERIFICANDO PARÂMETROS
    if(argc != 5){
        cerr  <<"Parâmetros inválidos. Informe: "<< endl 
        << " 1. O algoritmo de substituição a ser usado (lru, fifo, nru, lfu e random)" << endl 
        << " 2. Arquivo de endereços" << endl 
        << " 3. Tamanho página - de 2 à 64" << endl 
        << " 4. Tamanho total da memória física - 128 à 16384." << endl;
		return 1;
    }

    string algoritmo = argv[1], arqEnderecos = argv[2], line;
	int tamPagina = atoi(argv[3]), tamMemoria = atoi(argv[4]);

    if(tamMemoria < 128 && tamMemoria > 16384){
        cerr << "ERRO: MEMÓRIA DEVE ESTAR ENTRE 128 E 16384." << endl;
        return 1;
    }
    if(tamPagina < 2 && tamPagina > 64 ){
        cerr << "ERRO! PÁGINA DEVE ESTAR ENTRE 2 E 64." << endl;
		return 1;
    }

    //Lendo arquivo que contém os endereços
    ifstream arqEndercos;	
    arqEndercos.open(argv[2], ios::in);

	if (!arqEndercos.is_open()){
		cerr  << "Erro ao abrir arquivo de leitura dos endereços." << endl;
		return 1;
	}

    //AlgoritmosSubstituicao *alg_subst = new AlgoritmosSubstituicao(tamMemoria,tamPagina,algoritmo);
    string palavra, operacao;
    int endDecimal, pagina, totalPalavras=0, paginasLidas=0, paginasEscritas = 0, paginasSujas=0, faltaPaginas=0,paginasRepetidas=0,result;
    Memoria* memoria = new Memoria(tamMemoria, tamPagina,algoritmo);

    while (!arqEndercos.eof()){
        getline(arqEndercos,palavra,' ');
        getline(arqEndercos,operacao);

        endDecimal = converterHexaToDecimal(palavra);
        totalPalavras++;
        pagina = endDecimal / 4;
        
        if(!operacao.compare("R")){
            if(memoria->leitura(pagina)){
                paginasLidas++;
                continue;
            }
            faltaPaginas++;
        }
        result = memoria->escrita(pagina);
        if(result == 1){     
            paginasEscritas++;
            continue;
        }
        else if(result == 2){
            paginasRepetidas++;
            continue;
        }
        paginasSujas++;           
    }

    gerarRelatorio(tamMemoria,tamPagina,algoritmo,totalPalavras,paginasLidas,faltaPaginas,paginasSujas,paginasEscritas,paginasRepetidas);
    arqEndercos.close();

 }
