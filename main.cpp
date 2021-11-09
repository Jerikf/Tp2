#include "./entidades/firmas/Material.h"
#include "./entidades/firmas/Edificio.h"
#include "./entidades/firmas/Escuela.h"
#include "./entidades/firmas/Aserradero.h"
#include "./entidades/firmas/Mina.h"
#include "./estructura/Vect.h"
#include "./accesoDatos/modelo/Datos.h"
#include "./entidades/firmas/Casillero.h"
#include "./entidades/firmas/Transitable.h"
#include "./entidades/firmas/Construible.h"
#include "./entidades/firmas/Inaccesible.h"
#include <iostream>

int main(){
    //Edificio edificio("escuelaa Prueba", 5, 56, 5, 3);
    /*Escuela escuela("escuelaa Prueba", 5, 56, 5, 3);
    escuela.mostrar();
    Edificio* ptr = new Escuela("madre admirable", 5, 6, 3, 2);
    ptr->mostrar();
    delete ptr;*/

    //--------------------------------- otra prueba------------------------
    /*Vect<Edificio> edificios;
    Edificio* escuela = new Escuela("san josé",1,1,1,1);
    Edificio* escuela2 = new Escuela("lavalle",2,2,2,2);
    Edificio* edificio;
    string nombreEdificio = "Aserradero";
    if(nombreEdificio == "Escuela"){
        edificio = new Escuela("Corrientes",3,3,3,3);
    }else if(nombreEdificio == "Aserradero"){
        edificio = new Aserradero("Cordoba",4,4,4,4);
    }else{
        edificio = new Mina("Santa fe",5,5,5,5);
    }


    edificios.agregar(escuela);
    cout << edificios.obtenerCantidad() << endl;
    edificios.agregar(escuela2);
    cout << edificios.obtenerCantidad() << endl;
    edificios.agregar(edificio);
    cout << edificios.obtenerCantidad() << endl;
    edificios.mostrar();

    Edificio* valor = edificios.obtenerDato(2);
    valor->mostrar();

    Vect<Material> materiales;
    Material* material1 = new Material("Piedra",5);
    Material* material2 = new Material("Metal",3);
    Material* material3 = new Material("Madera",7);

    materiales.agregar(material1);
    materiales.agregar(material2);
    materiales.agregar(material3);

    cout << "La cantidad es : " << materiales.obtenerCantidad() << endl;
    materiales.mostrar();
    materiales.obtenerDato(1)->mostrar();*/

    //---------------------Probando el cargado de los datos del archivo
    
    /*Datos datos("edificios.txt","materiales.txt");
    Vect<Edificio> edificios2;
    cout << "\n\n\n" << endl;
    datos.cargarDatosEdificios(&edificios2);
    edificios2.mostrar();*/
    //------------------------------------------------------------


    //---------------------Probando el cargado de los datos del archivo materiales
    /*Datos datos("edificios.txt","materiales.txt");
    Vect<Material> materiales;
    datos.cargarDatosMateriales(&materiales);
    Material* nuevoMaterial = new Material("oro", 28);
    materiales.agregar(nuevoMaterial);
    cout << "\n\n" << endl;
    materiales.mostrar();
    cout << "\n\n" << endl;
    datos.guardarDatosMateriales(&materiales);*/

     //------------------------------------------------------------
     /*Edificio* edificio = new Escuela("san josé",1,2,3,4);
     cout << edificio->getNombre() << endl;
     cout << edificio->getCantPiedra() << endl;
     cout << edificio->getCantMadera() << endl;
     cout << edificio->getCantMetal() << endl;*/

    //------------------------------------------------------------
    
    /* ---------SE PROBÒ EL USO DE CARGADO DE LOS DATOS EDIFICIOS
    Datos datos("edificios.txt", "materiales.txt");
    Vect<Edificio> edificios;
    datos.cargarDatosEdificios(&edificios);
    Edificio* edificio = new Escuela("escuela", 1,2,3,4);
    edificios.agregar(edificio);
    datos.gurdarDatosEdificios(&edificios);
    edificios.mostrar();

    -----------------------------------------------------------*/

    /* -------probe el uso de los casilleros instanciando los constructores con valores además del
    del método contruirEdificio que se redifine según sea el casillero---------*/
    Vect<Casillero> casilleros;

    Material* material1 = new Material("Piedra", 10);
    Material* material2 = new Material("Metal", 5);

    Edificio* edificio1 = new Escuela("Madre Admirable", 1,1,1,1);
    Edificio* edificio2 = new Fabrica("Taller de Textil", 2,2,2,2);
    Edificio* edificio3 = new Fabrica("Los pasos", 3,3,3,3);

  
    Casillero* casillero1 = new Transitable('C',material1);
    Casillero* casillero2 = new Transitable('C',material2);
    Casillero* casillero3 = new Construible('T',edificio1);
    Casillero* casillero4 = new Construible('T',edificio2);
    Casillero* casillero5 = new Inaccesible('L');
    

    casilleros.agregar(casillero1);
    casilleros.agregar(casillero2);
    casilleros.agregar(casillero3);
    casilleros.agregar(casillero4);
    casilleros.agregar(casillero5);


    casilleros.mostrar();
    
    Casillero* casillero6 = new Transitable('C');
    Casillero* casillero7 = new Construible('T');

    casillero6->construirEdificio(edificio3); //acá si se debe construir
    casillero7->construirEdificio(edificio3); //acá no se debería poder

    if(casillero6->getEdificio()){
        casillero6->getEdificio()->getNombre();
    }
    if(!casillero7->getEdificio()){ //osea quiere decir que está null que no lo guardó acá
        cout << "está vacío" << endl;
    }
    delete casillero6;
    delete casillero7;
    delete edificio3; //llamo a este porque contruirEdificio te genera otro nueva instancia


    return 0;
}