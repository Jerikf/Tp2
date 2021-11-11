#include "../firma/Interfaz.h"
#include <iostream>

const int CONSTRUIR_EDIFICIO_POR_NOMBRE = 1;
const int LISTAR_LOS_EDIFICIOS_CONSTRUIDOS = 2;
const int LISTAR_TODOS_LOS_EDIFICIOS = 3;
const int DEMOLER_EDIFICIO_POR_COORDENADA = 4;
const int MOSTRAR_MAPA = 5;
const int CONSULTAR_COORDENADA = 6;
const int MOSTRAR_INVENTARIO = 7;
const int RECOLECTAR_RECURSOS_PRODUCIDOS = 8;
const int LLUVIA_DE_RECURSOS = 9;
const int GUARDAR_SALIR = 10;

bool Interfaz::validarOpcion(int opcion){
    return (opcion >= 1 && opcion <= 10);
}

int Interfaz::obtenerOpcion(){
    int opcion = 0;
	bool esValido = false;
	while(!esValido){
		cout << "\n\n";
		cout << "SELECCIONE UNA OPCIÒN DEL 1 AL 10 " << endl;
		cin >> opcion;
		if(this->validarOpcion(opcion))
			esValido = true;
		else
			cout << "OPCIÓN INCORRECTA!" << endl;
	}
	return opcion;
}

Interfaz::Interfaz(Juego* juego){
    this->juego = juego;
}

Interfaz::~Interfaz(){}


void Interfaz::iniciar(){

    int opcion ;
	Coordenada coordenada;
    int fila, columna = 0;
	string nombre = "";
	bool salir = false;
	do{
		this->juego->mostrarMenu();
		opcion = this->obtenerOpcion();
		switch (opcion){
			case CONSTRUIR_EDIFICIO_POR_NOMBRE:

                cout << "\n\n\n";
				cout << "		CONSTRUCCIÓN DEL EDIFICIO" << endl;
				cout << "\nINGRESE EL NOMBRE DEL EDIFICIO PARA CONSTRUIRLO" << endl;
				cin >> nombre;
				cout << "\n" ;

                cout << "\n SE PEDIRÁ UNA COORDENADA INGRESANDO PRIMERO LA FILA Y LUEGO LA COLUMNA" << endl;
                cout << "\nINGRESE LA FILA" << endl;
                cin >> fila;
                cout << "\nINGRESE LA COLUMNA" << endl;
                cin >> columna;

                coordenada.setFila(fila);
				coordenada.setColumna(columna);

				this->juego->construirEdificioPorNombre(nombre, coordenada);
				break;

			case LISTAR_LOS_EDIFICIOS_CONSTRUIDOS:

				cout << "\n\n\n";
				this->juego->listarEdificiosConstruidos();
				cout << "\n\n";
				break;

			case LISTAR_TODOS_LOS_EDIFICIOS:

                cout << "\n\n\n";

                this->juego->listarTodosLosEdificios();
				break;

			case DEMOLER_EDIFICIO_POR_COORDENADA:

                cout << "\n\n\n";
				cout << "DEMOLICIÓN DE UN EDIFICIO POR COORDENADA" << endl;
                cout << "\nINGRESE LA FILA" << endl;
                cin >> fila;
                cout << "\nINGRESE LA COLUMNA" << endl;
                cin >> columna;

                coordenada.setFila(fila);
				coordenada.setColumna(columna);

				this->juego->demolerEdificioPorCoordenada(coordenada);
				break;

			case MOSTRAR_MAPA:
            
				cout << "\n\n\n";
				cout << "		SE MOSTRARÁ EL MAPA" << endl;
				//TODO --> falta implementar el mostrar mapa adecuado
				cout << "\n\n";
				break;

			case CONSULTAR_COORDENADA:

				cout << "\n\n\n";
				cout << "CONSULTAR COORDENADA" << endl;
				cout << "\nINGRESE LA FILA" << endl;
                cin >> fila;
                cout << "\nINGRESE LA COLUMNA" << endl;
                cin >> columna;

				coordenada.setFila(fila);
				coordenada.setColumna(columna);

				this->juego->consultarCoordenada(coordenada);
				break;

			case MOSTRAR_INVENTARIO:

				cout << "\n\n\n";
				cout << "MUESTRA DE INVENTARIO" << endl;
				this->juego->mostrarInventario();
				break;

			case RECOLECTAR_RECURSOS_PRODUCIDOS:

				cout << "\n\n\n";
				cout << "RECOLECTOR DE RECURSOS PRODUCIDOS" << endl;
				this->juego->recolectarRecursosProducidos();
				break;

			case LLUVIA_DE_RECURSOS:

				cout << "\n\n\n";
				cout << "LLUVIA DE RECURSOS" << endl;
				//TODO --> falta construir dicho método en el juego
				break;

			case GUARDAR_SALIR:

				cout << "\n\n\n";
				cout << "GUARDAR Y SALIR" << endl;
				this->juego->guardarSalir();
				salir = true;
				break;

			default :
				cout << "INGRESÒ UNA OPCIÓN INCORRECTA!!!" << endl;
				break;
		}
	}while(!salir);

	cout << "\n\n\n-------------------------HASTA LA PRÓXIMA-----------------------" << endl;
}


