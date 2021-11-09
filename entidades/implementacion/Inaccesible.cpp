#include "../firmas/Inaccesible.h"
#include <iostream>

Inaccesible::Inaccesible(){}
Inaccesible::Inaccesible(char tipo) : Casillero(tipo){}
Inaccesible::~Inaccesible(){}
void Inaccesible::mostrar(){
        this->mostrarTipo();
        cout << "Acá no hay nada --> casillero Inaccesible" << endl;
    
}
void Inaccesible::construirEdificio(Edificio* edificio){}
Edificio* Inaccesible::getEdificio(){
    return NULL;
}

Material* Inaccesible::getMaterial(){
    return NULL;
}