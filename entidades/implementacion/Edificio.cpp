#include "../firmas/Edificio.h"
#include <iostream>

void Edificio::mostrar(){
    cout << "soy Padre" << endl;
}

Edificio::Edificio(string nombre, int cantPiedra, int cantMadera, int cantMetal, int cantMaxPermitidos){
    this->nombre = nombre;
    this->cantPiedra = cantPiedra;
    this->cantMadera = cantMadera;
    this->cantMetal = cantMetal;
    this->maxCantPermitidos = cantMaxPermitidos;
}
//Edificio::Edificio(){}

Edificio::~Edificio(){}


string Edificio::getNombre(){
    return this->nombre;
}

int Edificio::getCantPiedra(){
    return this->cantPiedra;
}

int Edificio::getCantMadera(){
    return this->cantMadera;
}

int Edificio::getCantMetal(){
    return this->cantMetal;
}

int Edificio::getMaxCantPermitidos(){
    return this->maxCantPermitidos;
}



