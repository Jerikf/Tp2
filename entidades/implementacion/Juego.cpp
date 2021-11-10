#include "../firmas/Juego.h"
#include <iostream>

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
void Juego::listarEdificiosConstruidos(){
}
void Juego::listarTodosLosEdificios(){
    this->edificios->mostrar();
}
void Juego::mostrarInventario(){
    this->materiales->mostrar();
}