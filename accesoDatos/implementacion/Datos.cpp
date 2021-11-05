#include "../modelo/Datos.h"
#include <iostream>
#include <fstream>

const string PLATAN_ELECTRICA = "planta electrica";
const string ASERRADERO = "aserradero";
const string OBELISCO = "obelisco";
const string FABRICA = "fabrica";
const string ESCUELA = "escuela";
const string MINA = "mina";
const string PLANTA = "planta";

Datos::Datos(string nombreArchivoEdificios, string nombreArchivoMateriales){
    this->nombreArchivoEdificios = nombreArchivoEdificios;
    this->nombreArchivoMateriales = nombreArchivoMateriales;
}

Datos::~Datos(){}

void Datos:: cargarDatosEdificios(Vect<Edificio>* edificios){

    fstream archivoEdificios(this->nombreArchivoEdificios, ios::in);
	if(!archivoEdificios.is_open()){
		cout << "NO SE ENCONTRÒ EL ARCHIVO" << endl;
		archivoEdificios.open(this->nombreArchivoEdificios, ios::out);
		archivoEdificios.close();
		archivoEdificios.open(this->nombreArchivoEdificios, ios::in);
	}
	string nombre, nombreComplemento, cantPiedra, cantMadera, cantMetal, cantMaxPermitidos;
	Edificio* edificio = NULL;
	while(archivoEdificios >> nombre){
        if(nombre == PLANTA){
            archivoEdificios >> nombreComplemento;
        }
		archivoEdificios >> cantPiedra;
		archivoEdificios >> cantMadera;
		archivoEdificios >> cantMetal;
		archivoEdificios >> cantMaxPermitidos;

		// verifico que edificio es y asigno los valores
        if(nombre + " " + nombreComplemento == PLATAN_ELECTRICA){
            edificio = new PlantaElectrica(nombre + " " + nombreComplemento,(int)stol(cantPiedra),(int)stol(cantMadera),(int)stol(cantMetal),(int)stol(cantMaxPermitidos));
        }else if(nombre == ASERRADERO){
            edificio = new Aserradero(nombre,(int)stol(cantPiedra),(int)stol(cantMadera),(int)stol(cantMetal),(int)stol(cantMaxPermitidos));
        }else if(nombre == OBELISCO){
            edificio = new Obelisco(nombre,(int)stol(cantPiedra),(int)stol(cantMadera),(int)stol(cantMetal),(int)stol(cantMaxPermitidos));
        }else if(nombre == FABRICA){
            edificio = new Fabrica(nombre,(int)stol(cantPiedra),(int)stol(cantMadera),(int)stol(cantMetal),(int)stol(cantMaxPermitidos));
        }else if(nombre == ESCUELA){
            edificio = new Escuela(nombre,(int)stol(cantPiedra),(int)stol(cantMadera),(int)stol(cantMetal),(int)stol(cantMaxPermitidos));
        }else if(nombre == MINA){
            edificio = new Mina(nombre,(int)stol(cantPiedra),(int)stol(cantMadera),(int)stol(cantMetal),(int)stol(cantMaxPermitidos));
        }else{
            cout << "NO HAY UN EDIFICIO RECONOCIBLE" << endl;
        }

        //Ahora lo agrego a vec de edificios
        if(edificio){
            edificios->agregar(edificio);
            edificio = NULL; // Sirve cuando NO exista un edificio reconcible no intente agregar otra vez el guardado anterior.
        }

	}

	archivoEdificios.close();
}

void Datos:: cargarDatosMateriales(Vect<Material>* materiales){
	fstream archivoMateriales(this->nombreArchivoMateriales, ios::in);
	if(!archivoMateriales.is_open()){
		cout << "NO SE ENCONTRÒ EL ARCHIVO " << this->nombreArchivoMateriales << endl;
		archivoMateriales.open(this->nombreArchivoMateriales, ios::out);
		archivoMateriales.close();
		archivoMateriales.open(this->nombreArchivoMateriales, ios::in);
	}

	string nombre, cantMaterial;
	Material* material;

	while(archivoMateriales >> nombre){
		archivoMateriales >> cantMaterial;

		material = new Material(nombre,(int)stol(cantMaterial));
		materiales->agregar(material);
	}

	archivoMateriales.close();
}

void Datos:: guardarDatosMateriales(Vect<Material>* materiales){
	ofstream archivoMateriales(this->nombreArchivoMateriales);
	for(int pos = 0; pos < materiales->obtenerCantidad(); pos++){
		archivoMateriales << materiales->obtenerDato(pos)->getNombre() << ' ' << materiales->obtenerDato(pos)->getCantidad() << '\n';
	}

}

void Datos::gurdarDatosEdificios(Vect<Edificio>* edificios){
	ofstream archivoEdificios(nombreArchivoEdificios);
	for(int pos = 0; pos < edificios->obtenerCantidad(); pos++){
		archivoEdificios << edificios->obtenerDato(pos)->getNombre() << ' '
										 << edificios->obtenerDato(pos)->getCantPiedra() << ' '
										 << edificios->obtenerDato(pos)->getCantMadera() << ' '
										 << edificios->obtenerDato(pos)->getCantMetal() << ' '
										 << edificios->obtenerDato(pos)->getMaxCantPermitidos() << '\n';
	}
}