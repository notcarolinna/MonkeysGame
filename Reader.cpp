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
	if (!file.is_open())
	{
		std::cout << "Erro ao abrir o arquivo." << std::endl;
		return this;
	}

	// Conta o número de linhas do arquivo, exceto a primeira linha
	// O número de linhas é útil pra determinar o tamanho do array de ponteiros
	// do Macaquinho

	totalMacaquinhos = std::count(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>(), '\n') - 1;
	macaquinhos = new Macaquinho * [totalMacaquinhos];

	// Volta ao início do arquivo

	file.clear();
	file.seekg(0, std::ios::beg);

	std::string line;
	int count = 0;

	// Lê cada linha do arquivo

	while (getline(file, line))
	{
		count++;

		if (count == 1)
		{
			// A primeira linha contém o número de rodadas
			int rodadasPos = line.find(" ");
			rodadas = std::stoi(line.substr(rodadasPos + 1));
		}
		else
		{
			// Cada linha subsequente contém as informações de um macaquinho
			std::istringstream ss(line);
			int macacoVencedor, macacoPar, macacoImpar;
			std::string trash;
			ss >> trash >> macacoVencedor >> trash >> trash >> macacoPar >> trash >> trash >> macacoImpar;

			Macaquinho* macaquinho = new Macaquinho(macacoVencedor, macacoImpar, macacoPar);

			// Adiciona as informações do macaquinho
			std::string info;
			int n;
			while (ss >> trash >> n >> trash && std::getline(ss, info))
			{
				std::stringstream ss2(info);

				for (int i = 0; i < n; i++)
				{
					std::string cocos;
					ss2 >> cocos;

					int coco = stoi(cocos);

					if (coco % 2 == 0)
					{
						macaquinho->addCocosPares(1);
					}
					else
					{
						macaquinho->addCocosImpares(1);
					}
				}
			}

			macaquinhos[count - 2] = macaquinho;
		}
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
