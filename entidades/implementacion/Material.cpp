#include "../firmas/Material.h"
#include "../../recursos/firmas/Recursos.h"
#include <iostream>

void Material::mostrar(){
    Recurso recurso;

    cout << "\n\n"; 
	cout << "|---------------------------------------------|" << endl;
	cout << "		" << recurso.convertirAMayuscula(this->nombre) << endl;
	cout << "	" << "CANDTIDAD MATERIAL : " << this->cantidad << endl;
	cout << "|---------------------------------------------|" << endl;
	cout << "\n"; 
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
void Material::setCantidad(int cantidad){
    this->cantidad = cantidad;
}
