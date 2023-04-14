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
    if (!file.is_open()) {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
        return this;
    }

    std::istream& input = file;

    input >> trash >> rodadas >> trash;

    int num_macaquinhos = 0;

    // Conta o número de linhas no arquivo (cada linha representa um macaquinho)
    while (std::getline(input, trash)) {
        num_macaquinhos++;
    }
    num_macaquinhos -= 2;

    // Volta para o início do arquivo
    input.clear();
    input.seekg(0, std::ios::beg);

    // Lê cada linha do arquivo e cria um objeto Macaquinho correspondente
    macaquinhos = new Macaquinho * [num_macaquinhos];

    std::getline(input, trash); // pula a primeira linha

    for (int i = 0; i < num_macaquinhos; i++) {
        std::getline(input, trash);

        std::istringstream ss(trash);

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
