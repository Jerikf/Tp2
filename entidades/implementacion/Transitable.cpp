#include "../firmas/Transitable.h"
#include <iostream>

Transitable::Transitable(){
    this->material = NULL;
}

Transitable::Transitable(char tipo, Material* material) : Casillero(tipo){
    this->material = material;
}

Transitable::Transitable(char tipo) : Casillero(tipo){
    this->material = NULL;
}

Transitable::~Transitable(){
    delete material;
}

Material* Transitable::getMaterial(){
    return this->material;
}

void Transitable::setMaterial(Material* material){
    this->material = material;
}

void Transitable::mostrar(){
    if(this->material){
        this->material->mostrar();
        this->mostrarTipo();
    }else{
        cout << "Estoy vacío --> casillero Transitable" << endl;
    }
    
}

void Transitable::construirEdificio(Edificio* edificio){}
Edificio* Transitable::getEdificio(){
    return NULL;
}