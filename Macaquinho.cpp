#include "Macaquinho.h"

Macaquinho::Macaquinho(int macacoVencedor, int macacoImpar, int macacoPar)
{
    this->macacoVencedor = macacoVencedor;
    this->macacoImpar = macacoImpar;
    this->macacoPar = macacoPar;
    this->cocosImpar = 0;
    this->cocosPar = 0;
}


int Macaquinho::getMacacoVencedor()
{
    return macacoVencedor;
}

int Macaquinho::getMacacoImpar()
{
    return macacoImpar;
}

int Macaquinho::getMacacoPar()
{
    return macacoPar;
}



void Macaquinho::addCocosImpares(int Cocos)
{
    cocosImpar += Cocos;
}
void Macaquinho::addCocosPares(int Cocos)
{
    cocosPar += Cocos;
}

int Macaquinho::getCocos()
{
    return cocosPar + cocosImpar;
}

int Macaquinho::getCocosImpar()
{
    return cocosImpar;
}

int Macaquinho::getCocosPar()
{
    return cocosPar;
}
