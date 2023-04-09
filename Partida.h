#pragma once
#include "Macaquinho.h"
#include "Reader.h"

class Partida {
private:
	Macaquinho** macaquinhos;
	Reader reader;

public:
	Partida(Macaquinho** macaquinhos, Reader reader);
	Macaquinho* Vencedor();
	void IniciarPartida();
};
