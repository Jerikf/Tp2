#include "../firmas/Juego.h"
#include "../../recursos/firmas/Recursos.h"
#include <iostream>

const int VACIO = 0;
//const int EXITO = 0;
const string PIEDRA = "piedra";
const string MADERA = "madera";
const string METAL = "metal";


//----------------------------IMPLEMENTACIÓN DE FUNCIONES PRIVADAS---------------------------------------
Vect<Coordenada>* Juego::obtenerCoordenadas(string nombreEdificio){
    Vect<Coordenada>* coordenadasDelEdificioConstruido = new Vect<Coordenada>;
    Coordenada* coordenada = NULL;
    Edificio* edificio = NULL;

    for(int fil = 0; fil < this->mapa->getCantFilas(); fil++){
        for(int col = 0; col < this->mapa->getCantColumnas(); col++){
            coordenada = new Coordenada(fil,col);
            edificio = this->mapa->getCasillero(*coordenada)->getEdificio();
            if(edificio && edificio->getNombre() == nombreEdificio){
                coordenadasDelEdificioConstruido->agregar(coordenada);
            }else{
                delete coordenada; // libero porque no lo guardaré en mi Vect de coordenadas, sino perdería memoria
            }
        }
    }
    return coordenadasDelEdificioConstruido;
}

Material* Juego::obtenerMaterial(string nombreMaterial){
    int pos = 0;
    bool seEncontro = false;
    Material* material = NULL;
    while(!seEncontro && pos < this->materiales->obtenerCantidad()){
        material = this->materiales->obtenerDato(pos);
        if(material->getNombre() == nombreMaterial)
            seEncontro = true;
        pos++;
    }

    return material;
    
}

Edificio* Juego::obtenerEdificio(string nombreEdificio){

    Edificio* edificio = NULL;
    bool seEncontro = false;
    int pos = 0;
    while(!seEncontro && pos < this->edificios->obtenerCantidad()){
        edificio = this->edificios->obtenerDato(pos);
        if(edificio->getNombre() == nombreEdificio)
            seEncontro = true;
        else
            edificio = NULL;
        pos++;
        
    }
    return edificio;
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
    Vect<Coordenada>* coordenadasDelEdificioConstruido = NULL;
    string nombre;

	cout << "\n\n\n\n LISTADO DE TODOS LOS EDIFICIOS CONSTRUIDOS";
    for(int pos = 0; pos < this->edificios->obtenerCantidad(); pos++){

        nombre = this->edificios->obtenerDato(pos)->getNombre();
        coordenadasDelEdificioConstruido = this->obtenerCoordenadas(nombre);
        if(coordenadasDelEdificioConstruido->obtenerCantidad() != VACIO){
            //TODO --> ESTO PODRÍA IR EN RECURSOS, YA QUE SERÍA COMO UN SCHEMA DE MOSTRAR DATOS DE DISTINTA MANERA
            // IGUAL ACÁ NO APLICAN TANTO EL MODELO DE CAPAZ O RESPONSABILIDAD DE COSAS..

            cout << "\n\n"; 
            cout << "|---------------------------------------------|" << endl;
            cout << "		"<< recursos.convertirAMayuscula(nombre) << endl;
            cout << "	CANTIDAD CONSTRUIDOS :" << coordenadasDelEdificioConstruido->obtenerCantidad() << endl;
            cout << " COORDENADAS DE DONDE ESTÁN CONSTRUIDOS" << endl;
            coordenadasDelEdificioConstruido->mostrar();
            cout << "|---------------------------------------------|" << endl;
            cout << "\n"; 
        }
        delete coordenadasDelEdificioConstruido; //Libero así a la siguiente iteración no pierdo memoria
        coordenadasDelEdificioConstruido = NULL;
    }
}

void Juego::listarTodosLosEdificios(){
    Edificio* edificio = NULL;
    Vect<Coordenada>* coordenadasDelEdificioConstruido = NULL;
    cout << "       lISTADO DE TODOS LOS EDIFICIOS" ;
    for(int pos = 0; pos < this->edificios->obtenerCantidad(); pos++){
        edificio = this->edificios->obtenerDato(pos);
        coordenadasDelEdificioConstruido = this->obtenerCoordenadas(edificio->getNombre());
        edificio->mostrar();
        cout << "        CANTIDAD CONSTRUIDOS : " << coordenadasDelEdificioConstruido->obtenerCantidad() << endl;
        cout << "        FALTAN CONSTRUIR : " << edificio->getMaxCantPermitidos() - coordenadasDelEdificioConstruido->obtenerCantidad() << endl;
        cout << "|---------------------------------------------|" << endl;

        delete coordenadasDelEdificioConstruido;
        coordenadasDelEdificioConstruido = NULL;
    }
}

void Juego::construirEdificioPorNombre(string nombre, Coordenada coordenada){

    Vect<Coordenada>* coordenadasDelEdificioConstruido  = NULL;
    Casillero* casillero = NULL;
    Edificio* edificio = NULL;
    Material* piedra = NULL;
    Material* madera = NULL;
    Material* metal = NULL;

    //Verifico que el nombre del edificio exista
    edificio = this->obtenerEdificio(nombre);
    if(edificio){

        //Verifico que la cantidad de materiales sea el adecuado
        piedra = this->obtenerMaterial(PIEDRA);
        madera = this->obtenerMaterial(MADERA);
        metal = this->obtenerMaterial(METAL);

        if(piedra->getCantidad() > edificio->getCantPiedra() && madera->getCantidad() > edificio->getCantMadera() && metal->getCantidad() > edificio->getCantMetal()){
            
            //Verifico que la cantidad de construidos sea el adecuado
            coordenadasDelEdificioConstruido = this->obtenerCoordenadas(edificio->getNombre()); // al saber las coordenas tengo ya la cantidad de veces que se construyeron asi reutilizo la funcion y no me creo otra igual
            if(coordenadasDelEdificioConstruido->obtenerCantidad() < edificio->getMaxCantPermitidos()){

                //Verifico que la coordenada sea válida!
                casillero = this->mapa->getCasillero(coordenada);
                if(casillero){

                    //Si es exitoso la construccion debo descontar los materiales usados
                    if(casillero->construirEdificio(edificio) == EXITO){
                        piedra->setCantidad(piedra->getCantidad() - edificio->getCantPiedra());
                        madera->setCantidad(madera->getCantidad() - edificio->getCantMadera());
                        metal->setCantidad(metal->getCantidad() - edificio->getCantMetal());
                    } 
                    
                }else
                    cout << "\n\n ERROR --> NO SE PUEDE CONTRUIR EDIFICIO PORQUE LA COORDENADA ESTÁ FUERA DE RANGO DEL MAPA \n\n" << endl;

            }else
                cout << "\n\n ERROR --> NO SE PUEDE CONTRUIR EDIFICIO PORQUE NO YA ALCANZÓ SU LÍMITE DE CANTIDAD PERMITIDO \n\n" << endl;

        }else
            cout << "\n\n ERROR --> NO SE PUEDE CONTRUIR EDIFICIO PORQUE NO HAY SUFICIENTE MATERIAL PARA CONSTRUIR EL EDIFICIO \n\n" << endl;

        

    }else
        cout << "\n\n ERROR --> NO SE PUEDE CONTRUIR EDIFICIO PORQUE NO EXISTE EL NOMBRE DEL EDIFICIO \n\n" << endl;
    delete coordenadasDelEdificioConstruido;
}
