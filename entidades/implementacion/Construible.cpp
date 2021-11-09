#include "../firmas/Construible.h"
#include <iostream>

#include "../firmas/PlantaElectrica.h"
#include "../firmas/Aserradero.h"
#include "../firmas/Obelisco.h"
#include "../firmas/Fabrica.h"
#include "../firmas/Escuela.h"
#include "../firmas/Mina.h"




const string PLATAN_ELECTRICA = "planta electrica";
const string ASERRADERO = "aserradero";
const string OBELISCO = "obelisco";
const string FABRICA = "fabrica";
const string ESCUELA = "escuela";
const string PLANTA = "planta";
const string MINA = "mina";


Construible::Construible(){
    this->edificio = NULL;
}
Construible::~Construible(){
    delete edificio;
}
Construible::Construible(char tipo, Edificio* edificio): Casillero(tipo){
    this->edificio = edificio;
}
Construible::Construible(char tipo) : Casillero(tipo){
    this->edificio = NULL;
}

Edificio* Construible::getEdificio(){
    return this->edificio;
}

Material* Construible::getMaterial(){
    return NULL;
}

void Construible:: mostrar(){
    if(this->edificio){
        this->mostrarTipo();
        this->edificio->mostrar();
    }else{
        cout << "Estoy vacio --> Casillero construible" << endl;
    }
    
}

void Construible::construirEdificio(Edificio* edificio){
    Edificio* edificioConstruido = NULL;

    //Obtendo sus datos
    string nombre = edificio->getNombre();
    int cantPiedra = edificio->getCantPiedra();
    int cantMadera = edificio->getCantMadera();
    int cantMetal = edificio->getCantMetal();
    int cantMaxPermitidos = edificio->getMaxCantPermitidos();

    //Me genera una nueva instancia dependiendo de que tipo de Edificio sea
    if(PLATAN_ELECTRICA == nombre){
        edificioConstruido = new PlantaElectrica(nombre, cantPiedra, cantMadera, cantMetal, cantMaxPermitidos);
    }else if(ASERRADERO == nombre){
        edificioConstruido = new Aserradero(nombre, cantPiedra, cantMadera, cantMetal, cantMaxPermitidos);
    }else if(OBELISCO == nombre){
        edificioConstruido = new Obelisco(nombre, cantPiedra, cantMadera, cantMetal, cantMaxPermitidos);
    }else if(FABRICA == nombre){
        edificioConstruido = new Fabrica(nombre, cantPiedra, cantMadera, cantMetal, cantMaxPermitidos);
    }else if(ESCUELA == nombre){
        edificioConstruido = new Escuela(nombre, cantPiedra, cantMadera, cantMetal, cantMaxPermitidos);
    }else if(MINA == nombre){
        edificioConstruido = new Mina(nombre, cantPiedra, cantMadera, cantMetal, cantMaxPermitidos);
    }

    //Me construyo el edificio
    this->edificio = edificioConstruido;

}