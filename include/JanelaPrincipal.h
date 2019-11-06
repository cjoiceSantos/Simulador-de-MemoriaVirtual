#ifndef _JANELA_PRINCIPAL_H_
#define _JANELA_PRINCIPAL_H_

#include <iostream>
#include <fstream>
#include <string>
#include <gtkmm.h>

using namespace std;
using namespace Gtk;

class JanelaPrincipal : public Window
{
	private:
		VBox boxPrincipal;
		VBox boxCheckButtons;
		VBox boxInformacoes;

		HBox boxPrimeiraLinha;
		HBox boxSegundaLinha;
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