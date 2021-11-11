#include "../firmas/Inaccesible.h"
#include <iostream>

const int ERROR = -1;

Inaccesible::Inaccesible(){}
Inaccesible::Inaccesible(char tipo) : Casillero(tipo){}
Inaccesible::~Inaccesible(){}
void Inaccesible::mostrar(){
        this->mostrarTipo();
        cout << "Acá no hay nada --> casillero Inaccesible" << endl;
    
}
int Inaccesible::construirEdificio(Edificio* edificio){
    cout << "\n\n\n ERROR --> NO SE PUEDE CONSTRUIR EDIFICIO PORQUE SOY UN : CASILLERO INACCESIBLE\n" << endl;
    return ERROR;
}
Edificio* Inaccesible::getEdificio(){
    return NULL;
}

Material* Inaccesible::getMaterial(){
    return NULL;
}

Edificio* Inaccesible::demolerEdificio(){
    cout << "\n\n\n ERROR-> NO SE PUEDE DEMOLER EL EDIFICIO PORQUE SOY UN : CASILLERO INACCESIBLE" << endl;
    return NULL;
}