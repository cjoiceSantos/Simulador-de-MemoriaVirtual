#ifndef _NUM_H_
#define _NUM_H_

#include <random>

class num {
	private:
		int valor;
		std::random_device rd;
		std::default_random_engine gen;
		std::uniform_int_distribution<> dis;

	public:
		num(int limite);
		int gerar();
//		int getValor();
};

#endif
