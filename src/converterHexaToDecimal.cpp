#include "converterHexaToDecimal.h"

using namespace std;

// Converte a palavra em hexadecimal para decimal
int converterHexaToDecimal(string palavraHex){
    int valor;
    stringstream stream;
    stream << palavraHex;
    stream >> hex >> valor;
    return valor;
}