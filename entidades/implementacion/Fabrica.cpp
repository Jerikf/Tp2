#include "../firmas/Fabrica.h"
#include <iostream>

void Fabrica::mostrar(){
    cout << this->nombre << endl;
    cout << "cantidad piedra" << this->cantPiedra << endl;
}

Fabrica::Fabrica(string nombre, int cantPiedra, int cantMadera, int cantMetal, int cantMaxPermitidos) : Edificio(nombre,cantPiedra, cantMadera, cantMetal, cantMaxPermitidos){

}

Fabrica::~Fabrica(){}