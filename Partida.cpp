#include "Partida.h"
#include <iostream>
#include "Partida.h"
#include <vector>
#include <algorithm>

Partida::Partida(Macaquinho** macaquinhos, Reader reader) : macaquinhos(macaquinhos), reader(reader) {}

Macaquinho* Partida::Vencedor() {
	int n = reader.getTotalMacaquinhos();
	std::vector<Macaquinho*> macaquinhosVec(macaquinhos, macaquinhos + n);

	std::sort(macaquinhosVec.begin(), macaquinhosVec.end(), [](Macaquinho* a, Macaquinho* b) {
		return a->getCocos() < b->getCocos();
		});

	return macaquinhosVec.back();
}

void Partida::IniciarPartida() {
	int numRodadas = reader.getRodadas();

	// std::cout << reader.getTotalMacaquinhos() << std::endl;

	for (int i = 0; i < numRodadas; i++)
	{
		for (int j = 0; j < reader.getTotalMacaquinhos(); j++)
		{
			Macaquinho* macaquinho = macaquinhos[j];

			macaquinhos[macaquinho->getMacacoPar()]->addCocosPares(macaquinho->getCocosPar());
			macaquinho->addCocosPares(-1 * macaquinho->getCocosPar());

			macaquinhos[macaquinho->getMacacoImpar()]->addCocosImpares(macaquinho->getCocosImpar());
			macaquinho->addCocosImpares(-1 * macaquinho->getCocosImpar());
		}
	}
}
