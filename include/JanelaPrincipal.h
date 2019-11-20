#ifndef _JANELA_PRINCIPAL_H_
#define _JANELA_PRINCIPAL_H_

#include <gtkmm.h>
#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <sstream>
#include "converterHexaToDecimal.h"
#include "memoria.h"

using namespace std;
using namespace Gtk;

class JanelaPrincipal : public Window
{
	private:
		long quantidadeDeFrames;
		long quantidadeDePaginas;
		string nomeDoarquivo;
		vector<HBox*> informacoes;

		VBox boxPrincipal;

		HBox boxDados;
		VBox boxInformacoes;
		ScrolledWindow scrolledWindowInformacoes;


		VBox boxFrame;
		VBox boxPagina;
		VBox boxAlgoritimos;
		VBox boxArquivo;
		VBox boxBotaoSimular;

		HBox boxEscolherArquivo;

		Label labelFrame;
		Label labelPagina;
		Label labelAlgoritimo;
		Label labelArquivo;

		Entry entryFrame;
		Entry entryPagina;
		Entry entryEscolherAquivo;

		RadioButton radioButtonLfu;
		RadioButton radioButtonNru;
		RadioButton radioButtonLru;
		RadioButton radioButtonFifo;
		RadioButton radioButtonRandom;

		Button buttonSimular;
		Button buttonEscolherArquivo;
		
	public:

		JanelaPrincipal();
		~JanelaPrincipal();
		
		void funcaoBotaoSimular();
		void funcaoBotaoEscolherArquivo();
		void addInfo(string);
		void gerarRelatorio(int, int, string, int, int, int, int, int, int);
		int converterHexaToDecimal(string palavraHex);
};

#endif