#include "../firmas/Escuela.h"
#include <iostream>

void Escuela::mostrar(){
    cout << this->nombre << endl;
    cout << "cantidad piedra" << this->cantPiedra << endl;
}

Escuela::Escuela(string nombre, int cantPiedra, int cantMadera, int cantMetal, int cantMaxPermitidos) : Edificio(nombre,cantPiedra, cantMadera, cantMetal, cantMaxPermitidos){

}

Escuela::~Escuela(){}
