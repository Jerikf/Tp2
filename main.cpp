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
    Juego juego(datos, edificios, materiales); //TODO--> Puedo instanciar directamente  en el constructor, cuál serái lo mejor?


    //Cargo los datos del archivo
    juego.inicializarCargadoDatos();
    /* --------------------- PRUEBA DE CONSTRUIR EDIFICIO POR NOMBRE---------------------------
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
    */

    //------------------------PRUEBAS PARA LA DEMOLICIÓN DE UN EDIFICIO-----------------------------
    /*
    Coordenada coordenada1(100,2);
    Coordenada coordenada2(0,2);
    Coordenada coordenada3(0,5);
    Coordenada coordenada4(0,0);
    Coordenada coordenada5(4,7);
    
    cout << "\n------------------" << endl;

    juego.demolerEdificioPorCoordenada(coordenada1); // ERROR --> FUERA DE RANGO DE LAS COORDENADAS
    juego.demolerEdificioPorCoordenada(coordenada2); // ERROR --> CASILLERO VACÍO
    juego.demolerEdificioPorCoordenada(coordenada3); // ERROR --> ES UN CASILLERO TRANSITABLE
    juego.demolerEdificioPorCoordenada(coordenada4); // ERROR --> ES UN CASILLERO INACCESIBLE
    juego.demolerEdificioPorCoordenada(coordenada5); // OK --> DEMUELO UNA MINA

    juego.mostrarInventario(); // PARA CORROBORAR QUE SE DEVOLVIERON LOS MATERIALES CORRECTAMENTE
    juego.listarTodosLosEdificios(); // PARA CORROBORAR QUE SE HAYA DISMINUIDO LA MINA (PORQUE TIEN 2 CONSTRUIDOS)
    */

   //------------------------PRUEBAS PARA CONSULTAR COORDENADA-----------------------------
   /*
    Coordenada coordenada1(100,2);
    Coordenada coordenada2(0,2);
    Coordenada coordenada3(0,5);
    Coordenada coordenada4(0,0);
    Coordenada coordenada5(4,7);

    juego.consultarCoordenada(coordenada1); // ERROR --> COORDENADA FUERA DE RANGO
    juego.consultarCoordenada(coordenada2); // CASILLERO CONSTRUIBLE VACÍO
    juego.consultarCoordenada(coordenada3); // CASILLERO TRANSITABLE VACÌO
    juego.consultarCoordenada(coordenada4); // CASILLERO INACCESIBLE VACÌO
    juego.consultarCoordenada(coordenada5); // CASILLERO CONSTRUIBLE CON UNA MINA
    */

    //---------------------------------PRUEBA PARA RECOLECTAR LOS RECURSOS PRODUCIDOS------------------------------------
    
    /*
    juego.mostrarInventario(); // Me fijo como están mis materiales

    //Construiré 1 edificios en coordenas correctas

    Coordenada coordenada2(4,7);


    juego.construirEdificioPorNombre("fabrica",coordenada2);

    juego.recolectarRecursosProducidos(); //Debería recolectar de los 3 edificios que brinda mientras que mina se recolecta 2 veces

    
    
    juego.mostrarInventario(); // Comparo si se recolectaron los materiales producidos
    */

   //---> ^ↀᴥↀ^ ---> (＾• ω •＾) ---> =ටᆼට=

    //--------------------------------PRUEBO EL GUARDADO DE LOS DATOS-------------------------------------------

    //Construiré 1 edificios en coordenas correctas

    //Alcanza con construir 2 edificios y borrar 1 edificio ya que esto modifica las cantidades de los materiales y las ubicaciones, el mapa no cambia y los edificios tampoco
    /*Coordenada coordenada1(7,7);
    Coordenada coordenada2(5,9);
    Coordenada coordenada3(1,8); // coordenada donde está una mina

    cout << ".---------------------------------------" << endl;
    juego.construirEdificioPorNombre("aserradero", coordenada1);
    juego.construirEdificioPorNombre("escuela", coordenada2);
    juego.demolerEdificioPorCoordenada(coordenada3);

    juego.guardarSalir();
    */


   //---------------------------------PRUEBA DEL NÚMERO ALEATORIO----------------------------------------
   /*juego.lluviaDeRecursos();
   

   Coordenada coordenada1(0,5);
   Coordenada coordenada2(0,6);
   Coordenada coordenada3(1,5);
   Coordenada coordenada4(1,6);
   Coordenada coordenada5(1,7);
   Coordenada coordenada6(6,0);
   Coordenada coordenada7(6,1);

   juego.consultarCoordenada(coordenada1);
   juego.consultarCoordenada(coordenada2);
   juego.consultarCoordenada(coordenada3);
   juego.consultarCoordenada(coordenada4);
   juego.consultarCoordenada(coordenada5);
   juego.consultarCoordenada(coordenada6);
   juego.consultarCoordenada(coordenada7);

   juego.lluviaDeRecursos();
   juego.lluviaDeRecursos();

   juego.lluviaDeRecursos();
   juego.lluviaDeRecursos();
   juego.lluviaDeRecursos();
   juego.lluviaDeRecursos();

   juego.lluviaDeRecursos();
   juego.lluviaDeRecursos();*/

   //--------------------------------------PRUEBA DE MOSTRAR EL MAPA-------------------------------------
   juego.lluviaDeRecursos(); //Agrego algunos recursos para ver si se muestra en el mapa además de los edificios ya cargados
   juego.mostrarMapa();


   



    return 0;
}