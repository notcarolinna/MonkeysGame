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
	std::string trash;
	std::ifstream file("./resources/" + arquivo);
	std::string line;
	std::getline(file, line);

	if (!file.is_open()) {
		std::cout << "Erro ao abrir o arquivo." << std::endl;
		return this;
	}

	file >> trash >> rodadas >> trash;

	int num_macaquinhos = std::count_if(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>(), [](char c) { return c == '\n'; }) + 1;

	macaquinhos = new Macaquinho * [num_macaquinhos - 2];

	file.clear();
	file.seekg(0, std::ios::beg);

	// Lê cada linha do arquivo e cria um objeto Macaquinho correspondente

	for (int i = 0; i < num_macaquinhos - 2; i++) {
		std::getline(file, line);
		std::istringstream ss(line);

		int macacoVencedor, macacoPar, macacoImpar, numberCoconuts;
		ss >> trash >> macacoVencedor >> trash >> trash >> macacoPar >> trash >> trash >> macacoImpar >> trash >> numberCoconuts >> trash;

		Macaquinho* macaquinho = new Macaquinho(macacoVencedor, macacoImpar, macacoPar);

		int coco;
		for (int j = 0; j < numberCoconuts; j++) {
			ss >> coco;
			if (coco % 2 == 0) {
				macaquinho->addCocosPares(1);
			}
			else {
				macaquinho->addCocosImpares(1);
			}
		}

		macaquinhos[i] = macaquinho;
		totalMacaquinhos++;
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
