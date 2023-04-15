#include "Reader.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

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

    // Lê a primeira linha do arquivo para obter o número de rodadas
    file >> trash >> rodadas >> trash;

    // Lê as informações de cada macaquinho e cria um objeto Macaquinho correspondente
    std::vector<Macaquinho*> macaquinhos;

    while (true) {
        int macacoVencedor, macacoPar, macacoImpar, numberCoconuts;
        file >> trash >> macacoVencedor >> trash >> trash >> macacoPar >> trash >> trash >> macacoImpar >> trash >> numberCoconuts >> trash;

        if (file.eof()) {
            break;
        }

        Macaquinho* macaquinho = new Macaquinho(macacoVencedor, macacoImpar, macacoPar);

        int coco;
        for (int j = 0; j < numberCoconuts; j++) {
            file >> coco;
            if (coco % 2 == 0) {
                macaquinho->addCocosPares(1);
            }
            else {
                macaquinho->addCocosImpares(1);
            }
        }

        macaquinhos.push_back(macaquinho);
    }

    file.close();

    // Atualiza as informações do Reader
    totalMacaquinhos = macaquinhos.size();
    this->macaquinhos = new Macaquinho * [totalMacaquinhos];
    std::copy(macaquinhos.begin(), macaquinhos.end(), this->macaquinhos);

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
