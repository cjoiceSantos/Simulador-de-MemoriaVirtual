#include "JanelaPrincipal.h"

using namespace Gtk;
using namespace std;

/**
* @brief Construtor padrão da classe JanelaPrincipal
*/

JanelaPrincipal::JanelaPrincipal():
	labelFrame("Quantidade de frames: "),
	labelPagina("Quantidade de Paginas: "),
	labelAlgoritimo("Algotitimos: "),
	labelArquivo("Arquivo: "),
	labelRu("Ru"),
	labelNru("Nru"),
	labelLru("Lru"),
	labelFifo("Fifo"),
	labelRandom("Random"),
	buttonSimular("Simular"),
	buttonEscolherArquivo("Escolher arquivo")
{
	//Configurações da janela
	
	set_size_request(1000, 700); // Largura x Altura da tela
	set_title("Simulador de memoria virtual");
	add(boxPrincipal);

	// Adicionado as widgets na janela

	boxPrincipal.pack_start(boxDados, false, false);
	boxPrincipal.add(scrolledWindowInformacoes);
	
	boxDados.pack_start(boxFrame, PACK_SHRINK, 10);
	boxDados.pack_start(boxPagina, PACK_SHRINK, 10);
	boxDados.pack_start(boxAlgoritimos, PACK_SHRINK, 10);
	boxDados.pack_start(boxArquivo, PACK_SHRINK, 10);
	boxDados.pack_start(boxBotaoSimular, PACK_SHRINK, 10);

	boxFrame.pack_start(labelFrame, PACK_SHRINK, 10);
	boxFrame.pack_start(entryFrame, PACK_SHRINK);

	boxPagina.pack_start(labelPagina, PACK_SHRINK, 10);
	boxPagina.pack_start(entryPagina, PACK_SHRINK);

	boxAlgoritimos.pack_start(labelAlgoritimo, PACK_SHRINK, 10);
	boxAlgoritimos.pack_start(boxRu, PACK_SHRINK);
	boxAlgoritimos.pack_start(boxNru, PACK_SHRINK);
	boxAlgoritimos.pack_start(boxLru, PACK_SHRINK);
	boxAlgoritimos.pack_start(boxFifo, PACK_SHRINK);
	boxAlgoritimos.pack_start(boxRandom, PACK_SHRINK);

	boxArquivo.pack_start(labelArquivo, PACK_SHRINK, 10);
	boxArquivo.pack_start(boxEscolherArquivo, PACK_SHRINK);

	boxBotaoSimular.pack_start(buttonSimular, PACK_SHRINK, 37);

	boxRu.pack_start(checkButtonRu, PACK_SHRINK);
	boxRu.pack_start(labelRu, PACK_SHRINK, 3);

	boxNru.pack_start(checkButtonNru, PACK_SHRINK);
	boxNru.pack_start(labelNru, PACK_SHRINK, 3);

	boxLru.pack_start(checkButtonLru, PACK_SHRINK);
	boxLru.pack_start(labelLru, PACK_SHRINK, 3);

	boxFifo.pack_start(checkButtonFifo, PACK_SHRINK);
	boxFifo.pack_start(labelFifo, PACK_SHRINK, 3);

	boxRandom.pack_start(checkButtonRandom, PACK_SHRINK);
	boxRandom.pack_start(labelRandom, PACK_SHRINK, 3);

	boxEscolherArquivo.pack_start(entryEscolherAquivo, PACK_SHRINK);
	boxEscolherArquivo.pack_start(buttonEscolherArquivo, PACK_SHRINK);

	scrolledWindowInformacoes.add(boxInformacoes);

	// Conexão dos botões com suas ações
	buttonSimular.signal_clicked().connect(sigc::mem_fun(*this, &JanelaPrincipal::funcaoBotaoSimular));
	buttonEscolherArquivo.signal_clicked().connect(sigc::mem_fun(*this, &JanelaPrincipal::funcaoBotaoEscolherArquivo));

	// Mostrar todos os widgets
	show_all_children();
}

/**
* @brief Destrutor da classe JanelaPrincipal
*/

JanelaPrincipal::~JanelaPrincipal(){}

/**
* @brief Ação do botão "simular"
*/

void JanelaPrincipal::funcaoBotaoSimular()
{
	// Validação dos dados digitados
	try {
		quantidadeDeFrames = stol(entryFrame.get_text());
		quantidadeDePaginas = stol(entryPagina.get_text());
	}
	catch (exception &exception) {
		// Caso não forem validos mostra um aviso
		MessageDialog dialog(*this, "");
		dialog.set_secondary_text("Dados invalídos");
  		dialog.run();		
		return;
	}

	nomeDoarquivo = entryEscolherAquivo.get_text();
	FILE *file = fopen(nomeDoarquivo.c_str(), "r");
	if (!file) 
	{
		MessageDialog dialog(*this, "");
		dialog.set_secondary_text("Arquivo invalído");
  		dialog.run();
        return;
	}
	fclose(file);

	algoritimos.push_back(checkButtonRu.get_active());
	algoritimos.push_back(checkButtonNru.get_active());
	algoritimos.push_back(checkButtonLru.get_active());
	algoritimos.push_back(checkButtonFifo.get_active());
	algoritimos.push_back(checkButtonRandom.get_active());
}

/**
* @brief Ação do botão "escolher arquivo"
*/

void JanelaPrincipal::funcaoBotaoEscolherArquivo()
{
	FileChooserDialog dialog("Please choose a file", FILE_CHOOSER_ACTION_OPEN);
	dialog.set_transient_for(*this);

	dialog.add_button("_Cancel", RESPONSE_CANCEL);
	dialog.add_button("_Open", RESPONSE_OK);

	int result = dialog.run();

	if (result == RESPONSE_OK)
	{
		string fileName = dialog.get_filename();
		entryEscolherAquivo.set_text(fileName);
	} 
}

/**
* @brief Metodo que adiciona informações segunda parte da janela
*/

void JanelaPrincipal::addInfo(string texto)
{
	HBox *boxInformacaoUnica = new HBox;
	Label *informacao = new Label(texto);
	boxInformacoes.pack_start(*boxInformacaoUnica, PACK_SHRINK, 5);
	boxInformacaoUnica->pack_start(*informacao, PACK_SHRINK);
	boxInformacaoUnica->show();
	informacao->show();
}