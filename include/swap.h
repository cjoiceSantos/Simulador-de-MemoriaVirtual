/*A IDEIA SERIA QUE A SWAP TRANSFORMASSE O ENDEREÇO HEXADECIMAL PARA DECIMAL E A CONSULTA FOSSE A 
A PARTIR ENDEREÇO DECIMAL
*/

#include <map>
using namespace std;
class Swap{
    
    int totalPaginas;
    map<int, string> paginas; //endereço + letra (R ou W)
    
    Swap(map<string, string> enderecos, int totalPaginas);
    ~Swap();

    void getPagina();
    void gerarEndVirtual();
    int getTotalPaginas();
    map<int, string> getPaginas();
}