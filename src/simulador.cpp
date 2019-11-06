#include <iostream>
#include "stdlib.h"
#include <fstream>
#include <sstream>
#include "string.h"
#include "JanelaPrincipal.h"
#include <gtkmm/application.h>
//#include "principal.h"

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    JanelaPrincipal window;

    return app->run(window);

    // //Verificando parâmetros
    // cout << argc << endl;
    // if(argc != 5){
    //     cerr  <<"Parâmetros inválidos. Informe: "<< endl 
    //     << " 1. O algoritmo de substituição a ser usado (lru, fifo, nru, lfu e random)" << endl 
    //     << " 2. Arquivo de endereços" << endl 
    //     << " 3. Tamanho página - de 2 à 64" << endl 
    //     << " 4. Tamanho total da memória física - 128 à 16384." << endl;
    //     return 1;
    // }

    // string algoritmo = argv[1];
    // string arqEnderecos = argv[2];
    // int tamPagina = atoi(argv[3]), tamMemoria = atoi(argv[4]);

    // /* if(algoritmo == "lru" || algoritmo == "fifo" || algoritmo == "nru" || algoritmo == "lfu" && algoritmo != "random"){
    //         cerr << "ERRO: ALGORITMO DE SUBSTITUIÇÃO INVÁLIDO." << endl;
    //         return 1;
    // } */

    // if(tamMemoria < 128 && tamMemoria > 16384){
    //     cerr << "ERRO: MEMÓRIA DEVE ESTAR ENTRE 128 E 16384." << endl;
    //     return 1;
    // }
    // if(tamPagina < 2 && tamPagina > 64 ){
    //     cerr << "ERRO! PÁGINA DEVE ESTAR ENTRE 2 E 64." << endl;
    //     return 1;
    // }

    // //Lendo arquivo que contém os endereços
    // ifstream arqEndercos;	

    // arqEndercos.open(argv[2], ios::in);
    // if (!arqEndercos.is_open()){
    //     cerr  << "Erro ao abrir arquivo de leitura dos endereços." << endl;
    //     return 1;
    // }
}
