#include "../firmas/PlantaElectrica.h"
#include <iostream>

void PlantaElectrica::mostrar(){
    cout << this->nombre << endl;
    cout << "cantidad piedra" << this->cantPiedra << endl;
}

PlantaElectrica::PlantaElectrica(string nombre, int cantPiedra, int cantMadera, int cantMetal, int cantMaxPermitidos) : Edificio(nombre,cantPiedra, cantMadera, cantMetal, cantMaxPermitidos){

}

PlantaElectrica::~PlantaElectrica(){}