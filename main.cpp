#include "./entidades/firmas/Material.h"
#include "./entidades/firmas/Edificio.h"
#include "./entidades/firmas/Escuela.h"
#include "./entidades/firmas/Aserradero.h"
#include "./entidades/firmas/Mina.h"
#include "./estructura/Vect.h"
#include "./entidades/firmas/Mapa.h"
#include "./accesoDatos/modelo/Datos.h"
#include "./entidades/firmas/Casillero.h"
#include "./entidades/firmas/Transitable.h"
#include "./entidades/firmas/Construible.h"
#include "./entidades/firmas/Inaccesible.h"
#include "./entidades/firmas/Juego.h"
#include <iostream>

int main(){
    //Defino las herramientas que utilizaré
    Datos* datos = new Datos("edificios.txt","materiales.txt","mapa.txt","ubicaciones.txt");
    Vect<Edificio>* edificios = new Vect<Edificio>; 
    Vect<Material>* materiales = new Vect<Material>;
    Juego juego(datos, edificios, materiales); //TODO--> Puedo directamente instanciar en el constructor, cuál serái lo mejor?


    //Cargo los datos del archivo
    juego.inicializarCargadoDatos();
    juego.mostrarMenu();
    juego.mostrarInventario();
    juego.listarEdificiosConstruidos();
    juego.listarTodosLosEdificios();

    Coordenada coordenada1(0,2);
    Coordenada coordenada2(5,8);
    Coordenada coordenada3(0,4);
    Coordenada coordenada4(0,2);
    Coordenada coordenada5(7,0);
    Coordenada coordenada6(7,7);
    Coordenada coordenada7(0,5);
    Coordenada coordenada8(0,0);
    Coordenada coordenada9(100,500);
    Coordenada coordenada10(7,8);
    Coordenada coordenada11(6,9);
  



    juego.construirEdificioPorNombre("mina", coordenada1); // LIMITE ALCANZADO
    juego.construirEdificioPorNombre("planta electrica", coordenada2); // OK
    juego.construirEdificioPorNombre("escuela",coordenada3); //   YA ESTÁ OCUPADO
    juego.construirEdificioPorNombre("aserradero",coordenada4); // OK
    juego.construirEdificioPorNombre("obelisco", coordenada5); //ERROR NOMBRE --> no está en la lista de edificios cargados
    juego.construirEdificioPorNombre("aserradero",coordenada6); // OK
    juego.construirEdificioPorNombre("aserradero",coordenada7); // ERROR--> Coordenada de un CAMINO
    juego.construirEdificioPorNombre("aserradero",coordenada8); // ERROR--> Coordenada de un LAGO
    juego.construirEdificioPorNombre("aserradero", coordenada9); // ERROR--> Coordeanda fuera de RANGO
    juego.construirEdificioPorNombre("escuela", coordenada10); // OK
    juego.construirEdificioPorNombre("escuela", coordenada11); // ERROR ---> FALTA MATERIAL(MADERA)


    juego.listarTodosLosEdificios();
    juego.listarEdificiosConstruidos();
    juego.mostrarInventario();


    return 0;
}