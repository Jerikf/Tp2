#include "../firmas/Juego.h"
#include "../../recursos/firmas/Recursos.h"
#include <iostream>

const int VACIO = 0;

//----------------------------IMPLEMENTACIÓN DE FUNCIONES PRIVADAS---------------------------------------
Vect<Coordenada>* Juego::obtenerCoordenadas(string nombreEdificio){
    Vect<Coordenada>* coordenadasDelLosEdificiosConstruidos = new Vect<Coordenada>;
    Coordenada* coordenada = NULL;
    Edificio* edificio = NULL;

    for(int fil = 0; fil < this->mapa->getCantFilas(); fil++){
        for(int col = 0; col < this->mapa->getCantColumnas(); col++){
            coordenada = new Coordenada(fil,col);
            edificio = this->mapa->getCasillero(*coordenada)->getEdificio();
            if(edificio && edificio->getNombre() == nombreEdificio){
                coordenadasDelLosEdificiosConstruidos->agregar(coordenada);
            }else{
                delete coordenada; // libero porque no lo guardaré en mi Vect de coordenadas, sino perdería memoria
            }
        }
    }
    return coordenadasDelLosEdificiosConstruidos;
}


Juego::Juego(Datos* datos, Vect<Edificio>* edificios, Vect<Material>* materiales){
    this->datos = datos;
    this->edificios = edificios;
    this->materiales = materiales;
    this->mapa = NULL;
}

Juego::~Juego(){
    delete datos;
    delete edificios;
    delete materiales;
    if(mapa)
        delete mapa;
}

void Juego::inicializarCargadoDatos(){
    this->datos->cargarDatosEdificios(this->edificios);
    this->datos->cargarDatosMateriales(this->materiales);
    this->datos->cargarDatosMapa(&(this->mapa));
    this->datos->cargarDatosUbicaciones(this->mapa, this->edificios);
}

void Juego::mostrarMenu(){
    cout << "\n\n\n";
	cout << "------------------MENU------------------" << endl;
	cout << "1.  CONSTRUIR EDIFICIO POR NOMBRE       |" << endl;
	cout << "2.  LISTAR EDIFICIOS CONSTRUIDOS        |" << endl;
	cout << "3.  LISTAR TODOS LOS EDIFICIOS          |" << endl;
	cout << "4.  DEMOLER UN EDIFICIO POR COORDENADA  |" << endl;
	cout << "5.  MOSTRAR MAPA                        |" << endl;
    cout << "6.  CONSULTAR COORDENADA                |" << endl;
    cout << "7.  MOSTRAR INVENTARIO                  |" << endl;
    cout << "8.  RECOLECTAR RECURSOS PRODUCIDOS      |" << endl;
    cout << "9.  LLUVIA DE RECURSOS                  |" << endl;
	cout << "10. GUARDAR Y SALIR                     |" << endl;
	cout << "----------------------------------------" << endl;
	cout << "\n\n";

}

void Juego::mostrarInventario(){
    this->materiales->mostrar();
}

void Juego::listarEdificiosConstruidos(){
    Recurso recursos;
    Vect<Coordenada>* coordenadasDelLosEdificiosConstruidos = NULL;
    string nombre;

	cout << "\n\n\n\n LISTADO DE TODOS LOS EDIFICIOS CONSTRUIDOS";
    for(int pos = 0; pos < this->edificios->obtenerCantidad(); pos++){

        nombre = this->edificios->obtenerDato(pos)->getNombre();
        coordenadasDelLosEdificiosConstruidos = this->obtenerCoordenadas(nombre);
        if(coordenadasDelLosEdificiosConstruidos->obtenerCantidad() != VACIO){
            //TODO --> ESTO PODRÍA IR EN RECURSOS, YA QUE SERÍA COMO UN SCHEMA DE MOSTRAR DATOS DE DISTINTA MANERA
            // IGUAL ACÁ NO APLICAN TANTO EL MODELO DE CAPAZ O RESPONSABILIDAD DE COSAS..

            cout << "\n\n"; 
            cout << "|---------------------------------------------|" << endl;
            cout << "		"<< recursos.convertirAMayuscula(nombre) << endl;
            cout << "	CANTIDAD CONSTRUIDOS :" << coordenadasDelLosEdificiosConstruidos->obtenerCantidad() << endl;
            cout << " COORDENADAS DE DONDE ESTÁN CONSTRUIDOS" << endl;
            coordenadasDelLosEdificiosConstruidos->mostrar();
            cout << "|---------------------------------------------|" << endl;
            cout << "\n"; 
        }
        delete coordenadasDelLosEdificiosConstruidos; //Libero así a la siguiente iteración no pierdo memoria
        coordenadasDelLosEdificiosConstruidos = NULL;
    }
}

void Juego::listarTodosLosEdificios(){
    this->edificios->mostrar();
}