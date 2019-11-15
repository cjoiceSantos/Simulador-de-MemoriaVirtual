#include <random>

#include "num.h"

num::num(int limite):rd(), gen(rd()), dis(0, limite){
	valor=std::round(dis(gen));
}

int num::gerar(){
	valor=std::round(dis(gen));
	return valor;
}

//int dado::getValor(){
//	return valor;
//}
