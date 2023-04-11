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

	// Conta o número de linhas no arquivo (cada linha representa um macaquinho)
	int num_macaquinhos = std::count_if(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>(), [](char c) { return c == '\n'; }) + 1;

	macaquinhos = new Macaquinho * [num_macaquinhos];

	// Volta para o início do arquivo
	file.clear();
	file.seekg(0, std::ios::beg);

	// Lê cada linha do arquivo e cria um objeto Macaquinho correspondente
	std::string line;
	for (int i = 0; i < num_macaquinhos; i++) {
		std::getline(file, line);
		std::istringstream ss(line);

		int macacoVencedor, macacoPar, macacoImpar;
		ss >> macacoVencedor >> macacoPar >> macacoImpar;

		Macaquinho* macaquinho = new Macaquinho(macacoVencedor, macacoImpar, macacoPar);

		int n, coco;
		ss >> n;
		for (int j = 0; j < n; j++) {
			ss >> coco;
			if (coco % 2 == 0) {
				macaquinho->addCocosPares(1);
			}
			else {
				macaquinho->addCocosImpares(1);
			}
		}

		macaquinhos[i] = macaquinho;
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
