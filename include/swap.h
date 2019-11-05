/*A IDEIA SERIA QUE A SWAP TRANSFORMASSE O ENDEREÇO HEXADECIMAL PARA DECIMAL E A CONSULTA FOSSE A 
A PARTIR ENDEREÇO DECIMAL
*/

#import <map>
using namespace std;
class Swap{
    
    int totalPaginas,
    Map<int,string> paginas, //endereço + letra (R ou W)
    
    Swap(Map<string,string> enderecos, int totalPaginas);
    ~Swap();

    void getPagina();
    void gerarEndVirtual();
    int getTotalPaginas();
    Map<int> getPaginas();
}