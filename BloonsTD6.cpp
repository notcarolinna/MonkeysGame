#include <iostream>
#include <chrono>
#include <vector>
#include "Partida.h"
#include "Reader.h"

void Jogo(const std::string arquivo, std::vector<std::pair<int, int>>& vencedores) {
	auto start = std::chrono::high_resolution_clock::now();

	std::cout << "Obtendo Resultados... ";

	Reader dados(arquivo);
	dados.Dados();

	Macaquinho** macaquinhos = dados.getMacaquinhos();
	Partida partida(macaquinhos, dados);
	partida.IniciarPartida();

	Macaquinho* vencedor = partida.Vencedor();
	vencedores.push_back(std::make_pair(vencedor->getMacacoVencedor(), vencedor->getCocos()));

	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	std::cout << "Tempo total de execucao: " << duration.count() << "ms." << std::endl;
}


int main()
{
	std::vector<std::pair<int, int>> vencedores;

	Jogo("caso0050.txt", vencedores);
	Jogo("caso0100.txt", vencedores);
	Jogo("caso0200.txt", vencedores);
	Jogo("caso0400.txt", vencedores);
	Jogo("caso0600.txt", vencedores);
	Jogo("caso0800.txt", vencedores);
	Jogo("caso0900.txt", vencedores);
	Jogo("caso1000.txt", vencedores);

	std::cout << "\nVencedores de cada caso:" << std::endl;
	for (auto& vencedor : vencedores) {
		std::cout << "Macaquinho #" << vencedor.first << " com " << vencedor.second << " cocos." << std::endl;
	}

	return 0;
}
