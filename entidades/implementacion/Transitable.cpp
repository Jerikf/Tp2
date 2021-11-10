#include "../firmas/Transitable.h"
#include <iostream>

const int ERROR = -1;


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

int Transitable::construirEdificio(Edificio* edificio){
    cout << "\n\n\n ERROR --> NO SE PUEDE CONSTRUIR EDIFICIO PORQUE SOY UN : CASILLERO TRANSITABLE\n" << endl;
    return ERROR;
}
Edificio* Transitable::getEdificio(){
    return NULL;
}