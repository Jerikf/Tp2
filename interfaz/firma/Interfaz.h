#ifndef INTERFAZ_H
#define INTERFAZ_H

#include "../../entidades/firmas/Juego.h"

class Interfaz
{
    private:
        Juego* juego;

        bool validarOpcion(int);
        int obtenerOpcion();

    public:

        //PRE: Recibe un juego, 
        //POS: Construye la interfaz, instancia el argumento pasado con el atributo
        Interfaz(Juego*);

        //PRE:
        //POS: Destructor
        ~Interfaz();

        //PRE:
        //POS: Inicializa el programa, donde se comenzará a escoger opciones del menu
        void iniciar();




};

#endif //INTERFAZ_H