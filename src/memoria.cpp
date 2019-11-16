#include "memoria.h"
#include <iostream>
#include <algorithm> 
#include <iterator> 
#include <random>

using namespace std;

set<int>::iterator it, aux;
int posicao; 

Memoria::Memoria(int tamMemoria, int tamFrame, string metSubstituicao): tamMemoria(tamMemoria), tamFrame(tamFrame), metSubstituicao(metSubstituicao){ 
    totalPaginasNaMemoria = tamMemoria/tamFrame;
    //criando uma matriz para o nru.==================================
    if (metSubstituicao == "nru"){
    	f = new int *[totalPaginasNaMemoria];
	for (n=0; n<totalPaginasNaMemoria; n++)
	    f[n] = new int[3];
    }	
    //================================================================
    //================================================================
}

Memoria::~Memoria(){}

//considerando o completamente associativo

int Memoria::escrita(int pagina){
    //verifico se a página ja está na memoria, te estiver não insere.
    if(leitura(pagina)){
        return 2;
    }

    if(frames.size() < totalPaginasNaMemoria){ // do 0 ate totalPaginasNaMemoria-1 
        
	//==============================================================================
	if (metSubstituicao == "nru"){
	    //na escrita o nru altera os campos de referencia e escrita.
	    for(n=0; n<totalPaginasNaMemoria; n ++){
                if(f[n][0] == pagina){
                    f[n][1] = 1;
		    f[n][2] = 1;
                }
            } 
	//==============================================================================
	    
    	}
	frames.insert(pagina);
        atualizarEstruturas(pagina);
        return 1;
    }
    substituir(pagina);
    return 0; 
}

bool Memoria::leitura(int pagina){ 	
    it = frames.find(pagina);
    if(it != frames.end()){

 	//se for no nru==================================
	if (metSubstituicao == "nru"){
	    for(n=0; n<totalPaginasNaMemoria; n ++){
                if(f[n][0] == pagina){
	            f[n][1] = 1;
	        }
            } 		
        }
	//================================================

    return true;
    }
    //chamar o metodo de substituir aqui tbm
    return false;
}

int Memoria::getTamMemoria(){
    return tamMemoria;
}
int Memoria::getTamFrame() {
    return tamFrame;
}

int Memoria::getTotalPaginasNaMemoria(){
    return totalPaginasNaMemoria;
}

set<int> Memoria::getFrame(){
    return frames;
}

void Memoria::print(){ 
    for (int it : frames){
        cout << it << " "; 
    }
}

void Memoria::random(int pagina){ 
    random_device rd;
	default_random_engine gen(rd());
	uniform_int_distribution<> dis(0,totalPaginasNaMemoria-1);
    //posição aleatoria
    posicao = dis(gen);
    it = frames.begin();
    advance(it, posicao); //função  advance avança o iterador fornecido ate enésimo elemento
    //removo a pagina antiga sorteada
    frames.erase(it);
    //adiciono a nova página.
    frames.insert(pagina);
}

int Memoria::lru(int pagina){}

int Memoria::fifo(int pagina){}



int Memoria::nru(int pagina){
    for(n=0; n<totalPaginasNaMemoria; n ++){
         if(f[n][1] == 0 && f[n][2] == 0){
              f[n][0] = pagina;
                }
            } 
}






int Memoria::lfu(int pagina){}

void Memoria::atualizarEstruturas(int pagina){
    //atualiza a fila
   // fila.push(pagina);
    //atualiza a frequência
   // aux = frequencia.find(pagina)
    //frequencia.insert(pagina, aux++);
}

void Memoria::substituir(int pagina){
    if(!metSubstituicao.compare("random")){
        random(pagina);
    } 
    if(!metSubstituicao.compare("lru")){
        lru(pagina);
    }
    if(!metSubstituicao.compare("fifo")){
        fifo(pagina);
    }
    if(!metSubstituicao.compare("nru")){
	//quando ocorre a falta de pagina no nru, ele zera todos os campos de 'referencia'
	//os campos de 'escrita' nunca são zerados.
	for(n=0; n<totalPaginasNaMemoria; n ++){  //para zerar os campos 'referencia' da matriz do nru
	    f[n][1] = 0;
	}
        lru(pagina);
    }
    if(!metSubstituicao.compare("lfu")){
        lru(pagina);
    }
}
