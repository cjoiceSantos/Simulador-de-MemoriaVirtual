#include "JanelaPrincipal.h"

using namespace Gtk;
using namespace std;

/**
* @brief Construtor padrão da classe JanelaPrincipal.
*/

JanelaPrincipal::JanelaPrincipal()
: labelFrame("Quantidade de frames: "),
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
	//Configuração dos atributos da classe GTK.
	
	set_size_request(1000, 700); // Tamnho x Altura da tela
	set_title("Simulador de memoria virtual");
	add(boxPrincipal);

	boxPrincipal.pack_start(boxPrimeiraLinha, PACK_SHRINK, 10);
	boxPrincipal.pack_start(boxSegundaLinha, PACK_SHRINK);
	boxPrincipal.add(boxInformacoes);

	boxPrimeiraLinha.pack_start(labelFrame, PACK_EXPAND_PADDING);
	boxPrimeiraLinha.pack_start(labelPagina, PACK_EXPAND_PADDING);
	boxPrimeiraLinha.pack_start(labelAlgoritimo, PACK_EXPAND_PADDING);
	boxPrimeiraLinha.pack_start(labelArquivo, PACK_EXPAND_PADDING);
	boxPrimeiraLinha.pack_start(buttonSimular, PACK_EXPAND_PADDING);

	boxSegundaLinha.pack_start(entryFrame, PACK_EXPAND_PADDING);
	boxSegundaLinha.pack_start(entryPagina, PACK_EXPAND_PADDING);
	boxSegundaLinha.pack_start(boxCheckButtons, PACK_EXPAND_PADDING);
	boxSegundaLinha.pack_start(boxEscolherArquivo, PACK_EXPAND_PADDING);

	boxCheckButtons.add(boxRu);
	boxCheckButtons.add(boxNru);
	boxCheckButtons.add(boxLru);
	boxCheckButtons.add(boxFifo);
	boxCheckButtons.add(boxRandom);

	boxRu.add(checkButtonRu);
	boxRu.add(labelRu);

	boxNru.add(checkButtonNru);
	boxNru.add(labelNru);

	boxLru.add(checkButtonLru);
	boxLru.add(labelLru);

	boxFifo.add(checkButtonFifo);
	boxRu.add(labelFifo);

	boxRandom.add(checkButtonRandom);
	boxRandom.add(labelRandom);

	boxEscolherArquivo.add(entryEscolherAquivo);
	boxEscolherArquivo.add(buttonEscolherArquivo);


	//Conexões dos atributos da classe GTK.
	buttonSimular.signal_clicked().connect(sigc::mem_fun(*this, &JanelaPrincipal::funcaoBotaoSimular));
	buttonEscolherArquivo.signal_clicked().connect(sigc::mem_fun(*this, &JanelaPrincipal::funcaoBotaoEscolherArquivo));

	// Mostrar todos os widgets.
	show_all_children();
}

/**
* @brief Destrutor da classe JanelaPrincipal.
*/

JanelaPrincipal::~JanelaPrincipal(){}

void JanelaPrincipal::funcaoBotaoSimular()
{
	try {
		long quantidadeDeFrames = stol(entryFrame.get_text());
		long quantidadeDePaginas = stol(entryPagina.get_text());
		string nomeDoarquivo = entryEscolherAquivo.get_text();
	}
	catch (exception &exception) {
		addInfo("Dados invalídos");
		return;
	}
}

void JanelaPrincipal::funcaoBotaoEscolherArquivo()
{
	FileChooserDialog dialog("Please choose a file", FILE_CHOOSER_ACTION_OPEN);
	dialog.set_transient_for(*this);

	dialog.add_button("_Cancel", RESPONSE_CANCEL);
	dialog.add_button("_Open", RESPONSE_OK);

	int result = dialog.run();

	if (RESPONSE_OK)
	{
		string fileName = dialog.get_filename();
		entryEscolherAquivo.set_text(fileName);
	} 
}

void JanelaPrincipal::addInfo(string texto)
{
	Label informacao(texto);
	boxInformacoes.add(informacao);
}