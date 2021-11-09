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

const char LAGO = 'L';
const char TERRENO = 'T';
const char CAMINO = 'C';

Datos::Datos(string nombreArchivoEdificios, string nombreArchivoMateriales, string nombreArchivoMapa, string nombreArchivoUbicaciones){
    this->nombreArchivoEdificios = nombreArchivoEdificios;
    this->nombreArchivoMateriales = nombreArchivoMateriales;
	this->nombreArchivoMapa = nombreArchivoMapa;
	this->nombreArchivoUbicaciones = nombreArchivoUbicaciones;
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

void Datos::cargarDatosMapa(Mapa** mapa){
	fstream archivoMapa(this->nombreArchivoMapa, ios::in);
	if(!archivoMapa.is_open()){
		cout << "NO SE ENCONTRÒ EL ARCHIVO " << this->nombreArchivoMapa << endl;
		archivoMapa.open(this->nombreArchivoMapa, ios::out);
		archivoMapa.close();
		archivoMapa.open(this->nombreArchivoMapa, ios::in);
	}

    string cantFilas, cantColumnas;
    archivoMapa >> cantFilas;
    archivoMapa >> cantColumnas;
    *mapa = new Mapa((int)stol(cantFilas),(int)stol(cantColumnas));
    char tipo;
    Casillero* casillero;


    for(int i = 0; i < (int)stol(cantFilas); i++){
        for(int j = 0; j < (int)stol(cantColumnas); j++){
            archivoMapa >> tipo;
            Coordenada coordenada(i,j);

            cout << tipo << " " ;
            
            if(tipo == CAMINO){
                casillero = new Transitable(tipo);
            }
            else if(tipo == TERRENO){
                casillero = new Construible(tipo);
            }else if(tipo == LAGO){
                casillero = new Inaccesible(tipo);
            }
            //agrego el casillero al mapa esto asumiendo que no vendrá un tipo que no fuera L-T-C
            (*mapa)->agregarCasillero(casillero, coordenada);
        }
        cout << "\n";
    }
	archivoMapa.close();
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

void Datos::guardarDatosMapa(Mapa* mapa){

    ofstream archivoMapa(this->nombreArchivoMapa);
    archivoMapa << mapa->getCantFilas() << ' ' << mapa->getCantColumnas() << '\n';

    for(int fila = 0; fila < mapa->getCantFilas(); fila++){
        for(int col = 0; col < mapa->getCantColumnas(); col++){
            Coordenada coordenada(fila,col);
            if(col == mapa->getCantColumnas()- 1){
                //Soluciona cuando llega al final de las columnas y no genere un espacio extra al final
                archivoMapa << mapa->getCasillero(coordenada)->getTipo();
            }else
                archivoMapa << mapa->getCasillero(coordenada)->getTipo() << ' ';
        }
        archivoMapa << '\n'; //Hago un salto de línea para generar la siguiente fila
    }
}
