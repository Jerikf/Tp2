#include "../firmas/Material.h"
#include <iostream>

void Material::mostrar(){
    cout << this->nombre << endl;
    cout << "cantidad Disponible es : " << this->cantidad << endl;
}

Material::Material(string nombre, int cantidad){
    this->nombre = nombre;
    this->cantidad = cantidad;
}

Material::~Material(){}

string Material::getNombre(){
    return this->nombre;
}

int Material::getCantidad(){
    return this->cantidad;
}
