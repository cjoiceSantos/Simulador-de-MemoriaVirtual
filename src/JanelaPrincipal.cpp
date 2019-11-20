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
	radioButtonLfu("LFU"),
	radioButtonNru("NRU"),
	radioButtonLru("LRU"),
	radioButtonFifo("FIFO"),
	radioButtonRandom("Random"),
	buttonSimular("Simular"),
	buttonEscolherArquivo("Escolher arquivo")
{
	//Configurações da janela
	
	set_size_request(1000, 700); // Largura x Altura da tela
	set_title("Simulador de memoria virtual");
	add(boxPrincipal);

	// Adicionado as widgets na janela
	boxPrincipal.pack_start(boxDados, false, false, 20);
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
	boxAlgoritimos.pack_start(radioButtonLfu, PACK_SHRINK);
	boxAlgoritimos.pack_start(radioButtonNru, PACK_SHRINK);
	boxAlgoritimos.pack_start(radioButtonLru, PACK_SHRINK);
	boxAlgoritimos.pack_start(radioButtonFifo, PACK_SHRINK);
	boxAlgoritimos.pack_start(radioButtonRandom, PACK_SHRINK);

	radioButtonNru.join_group(radioButtonLfu);
	radioButtonLru.join_group(radioButtonLfu);
	radioButtonFifo.join_group(radioButtonLfu);
	radioButtonRandom.join_group(radioButtonLfu);


	boxArquivo.pack_start(labelArquivo, PACK_SHRINK, 10);
	boxArquivo.pack_start(boxEscolherArquivo, PACK_SHRINK);

	boxBotaoSimular.pack_start(buttonSimular, PACK_SHRINK, 37);

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
	// Limpeza da tela
	for (HBox *informacao : informacoes)
	{
		boxInformacoes.remove(*informacao);
	}
	informacoes.clear();

	// Validação dos dados digitados
	try {
		quantidadeDeFrames = stoi(entryFrame.get_text());
		quantidadeDePaginas = stoi(entryPagina.get_text());
	}
	catch (exception &exception) {
		// Caso não forem validos mostra um aviso
		MessageDialog dialog(*this, "");
		dialog.set_secondary_text("Dados invalídos");
  		dialog.run();		
		return;
	}

	if(quantidadeDeFrames < 128 || quantidadeDeFrames > 16384){
		MessageDialog dialog(*this, "");
		dialog.set_secondary_text("A quantidade de frames tem que estar entre 128 e 16384");
  		dialog.run();		
		return;
    }
    if(quantidadeDePaginas < 2 || quantidadeDePaginas > 64 ){
        MessageDialog dialog(*this, "");
		dialog.set_secondary_text("A quantidade de paginas tem que estar entre 2 e 64");
  		dialog.run();		
		return;
    }

	nomeDoarquivo = entryEscolherAquivo.get_text();
	ifstream arqEndercos;
	arqEndercos.open(nomeDoarquivo, ios::in);
	if (!arqEndercos.is_open()) 
	{
		MessageDialog dialog(*this, "");
		dialog.set_secondary_text("Arquivo invalído");
  		dialog.run();
		arqEndercos.close();
        return;
	}

	string algoritmo;

	if (radioButtonLfu.get_active())
	{
		algoritmo = "lfu";
	}
	else if (radioButtonNru.get_active())
	{
		algoritmo = "nru";
	}
	else if (radioButtonLru.get_active())
	{
		algoritmo = "lru";
	}
	else if (radioButtonFifo.get_active())
	{
		algoritmo = "fifo";
	}
	else if (radioButtonRandom.get_active())
	{
		algoritmo = "random";
	}

	string palavra, operacao;
    int endDecimal;
	int pagina;
	int totalPalavras = 0;
	int paginasLidas = 0;
	int paginasEscritas = 0;
	int paginasSujas = 0;
	int faltaPaginas = 0;
	int paginasRepetidas = 0;
	int result;

    Memoria* memoria = new Memoria(quantidadeDeFrames, quantidadeDePaginas, algoritmo);

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

    gerarRelatorio(quantidadeDeFrames, quantidadeDePaginas, 
		algoritmo, totalPalavras,
		paginasLidas, faltaPaginas,
		paginasSujas, paginasEscritas, paginasRepetidas);
    arqEndercos.close();
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
	boxInformacoes.pack_start(*boxInformacaoUnica, PACK_SHRINK, 10);
	boxInformacaoUnica->pack_start(*informacao, PACK_SHRINK, 10);
	boxInformacaoUnica->show();
	informacao->show();
	informacoes.push_back(boxInformacaoUnica);
}

void JanelaPrincipal::gerarRelatorio(
	int tamMemoria, int tamPagina,string algoritmo, 
	int totalPalavras, int paginasLidas,
	int faltaPaginas, int paginasSujas, 
	int paginasEscritas, int paginasRepetidas
	){
	for(unsigned int i = 0; i < algoritmo.length(); i++)
			algoritmo[i] = toupper(algoritmo[i]);
	addInfo("TOTAL PAGINAS NA MEMÓRIA: " + to_string(tamMemoria / tamPagina));
	addInfo("ALGORITMO SUBSTITUIÇÃO: " + algoritmo);
	addInfo("PALAVRAS: " + to_string(totalPalavras));
	addInfo("TOTAL LEITURAS: " + to_string(paginasLidas+faltaPaginas));
	addInfo("		-SUCESSO: " + to_string(paginasLidas));
	addInfo("		-FALTA DE PÁGINA: "+ to_string( faltaPaginas));
	addInfo("TOTAL ESCRITAS: " + to_string(paginasEscritas+paginasSujas));
	addInfo("		-SUCESSO: " + to_string(paginasEscritas)); 
	addInfo("		-REPETIÇÃO: " + to_string(paginasRepetidas));
	addInfo("		-SUBSTITUIDAS: " + to_string(paginasSujas));
}