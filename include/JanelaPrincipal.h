#ifndef _JANELA_PRINCIPAL_H_
#define _JANELA_PRINCIPAL_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <gtkmm.h>

using namespace std;
using namespace Gtk;

class JanelaPrincipal : public Window
{
	private:
		long quantidadeDeFrames;
		long quantidadeDePaginas;
		string nomeDoarquivo;
		vector<bool> algoritimos;

		VBox boxPrincipal;

		HBox boxDados;
		VBox boxInformacoes;
		ScrolledWindow scrolledWindowInformacoes;


		VBox boxFrame;
		VBox boxPagina;
		VBox boxAlgoritimos;
		VBox boxArquivo;
		VBox boxBotaoSimular;

		HBox boxRu;
		HBox boxNru;
		HBox boxLru;
		HBox boxFifo;
		HBox boxRandom;

		HBox boxEscolherArquivo;


		Label labelFrame;
		Label labelPagina;
		Label labelAlgoritimo;
		Label labelArquivo;
		Label labelRu;
		Label labelNru;
		Label labelLru;
		Label labelFifo;
		Label labelRandom;

		Entry entryFrame;
		Entry entryPagina;
		Entry entryEscolherAquivo;

		CheckButton checkButtonRu;
		CheckButton checkButtonNru;
		CheckButton checkButtonLru;
		CheckButton checkButtonFifo;
		CheckButton checkButtonRandom;

		Button buttonSimular;
		Button buttonEscolherArquivo;
		
	public:

		JanelaPrincipal();
		~JanelaPrincipal();
		
		void funcaoBotaoSimular();
		void funcaoBotaoEscolherArquivo();
		void addInfo(string);
};

#endif