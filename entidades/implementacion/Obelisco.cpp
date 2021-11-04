#include "../firmas/Obelisco.h"
#include <iostream>

void Obelisco::mostrar(){
    cout << this->nombre << endl;
    cout << "cantidad piedra" << this->cantPiedra << endl;
}

Obelisco::Obelisco(string nombre, int cantPiedra, int cantMadera, int cantMetal, int cantMaxPermitidos) : Edificio(nombre,cantPiedra, cantMadera, cantMetal, cantMaxPermitidos){

}

Obelisco::~Obelisco(){}