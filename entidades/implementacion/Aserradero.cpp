#include "../firmas/Aserradero.h"
#include <iostream>

void Aserradero::mostrar(){
    cout << this->nombre << endl;
    cout << "cantidad piedra" << this->cantPiedra << endl;
}

Aserradero::Aserradero(string nombre, int cantPiedra, int cantMadera, int cantMetal, int cantMaxPermitidos) : Edificio(nombre,cantPiedra, cantMadera, cantMetal, cantMaxPermitidos){

}

Aserradero::~Aserradero(){}