#pragma once

class Macaquinho {
private:
	int macacoVencedor;
	int macacoImpar;
	int macacoPar;
	int cocosImpar;
	int cocosPar;

public:
	Macaquinho(int macacoVencedor, int macacoImpar, int macacoPar);

	int getMacacoVencedor();
	int getMacacoImpar();
	int getMacacoPar();

	void addCocosImpares(int Cocos);
	void addCocosPares(int Cocos);

	int getCocos();
	int getCocosImpar();
	int getCocosPar();

};
