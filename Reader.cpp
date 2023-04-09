#include "Reader.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

Reader::Reader() {
	totalMacaquinhos = 0;
	rodadas = 0;
	macaquinhos = nullptr;
}

Reader::Reader(std::string arquivo) {
	this->arquivo = arquivo;
	this->macaquinhos = NULL;
	this->rodadas = 0;
	this->totalMacaquinhos = 0;
}

Reader* Reader::Dados() {

	std::ifstream file("./resources/" + arquivo);

	if (!file.is_open()) {
		std::cout << "Erro ao abrir o arquivo." << std::endl;
		return this;
	}

	file >> rodadas;

	int num_macaquinhos = 0, idx = 0;

	std::string line;
	while (getline(file, line)) {
		num_macaquinhos++;
	}

	macaquinhos = new Macaquinho * [num_macaquinhos];
	file.clear();
	file.seekg(0, std::ios::beg);

	while (getline(file, line)) {
		std::istringstream ss(line);

		int macacoVencedor, macacoPar, macacoImpar;
		ss >> macacoVencedor >> macacoPar >> macacoImpar;

		Macaquinho* macaquinho = new Macaquinho(macacoVencedor, macacoImpar, macacoPar);

		int n, coco;
		ss >> n;
		for (int i = 0; i < n; i++) {
			ss >> coco;
			if (coco % 2 == 0) {
				macaquinho->addCocosPares(1);
			}
			else {
				macaquinho->addCocosImpares(1);
			}
		}

		macaquinhos[idx++] = macaquinho;
	}

	file.close();
	return this;
}

int Reader::getRodadas()
{
	return rodadas;
}

Macaquinho** Reader::getMacaquinhos()
{
	return macaquinhos;
}

int Reader::getTotalMacaquinhos()
{
	return totalMacaquinhos;
}
