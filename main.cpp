#include "./entidades/firmas/Material.h"
#include "./entidades/firmas/Edificio.h"
#include "./entidades/firmas/Escuela.h"
#include "./entidades/firmas/Aserradero.h"
#include "./entidades/firmas/Mina.h"
#include "./estructura/Vect.h"
#include "./accesoDatos/modelo/Datos.h"
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
    Datos datos("edificios.txt","materiales.txt");
    Vect<Material> materiales;
    datos.cargarDatosMateriales(&materiales);
    materiales.mostrar();







    return 0;
}