#pragma once
#include <string>
#include "Macaquinho.h"

class Reader {
private:
	Macaquinho** macaquinhos;
	std::string arquivo;
	int rodadas;
	int totalMacaquinhos;
	
public:
	Reader();
	Reader(std::string arquivo);
	Reader* Dados();

	Macaquinho** getMacaquinhos();
	int getRodadas();
	int getTotalMacaquinhos();
};
