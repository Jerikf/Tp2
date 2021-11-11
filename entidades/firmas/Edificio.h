#ifndef EDIFICIO_H
#define EDIFICIO_H
#include <stdbool.h>
#include <string>

using namespace std;

class Edificio
{
    protected:
        string nombre;
        int cantPiedra;
        int cantMadera;
        int cantMetal;
        int maxCantPermitidos;

    public:

        //PRE: Recibe un nombre, cantidades de piedra, madera, metal y un maximo permitido
        //POS: Construye el edificio instanciado con los valores pasados
        Edificio(string, int, int, int, int);

        //PRE: 
        //POS: Destruye el edificio
        virtual ~Edificio();

        //PRE:
        //POS: Muestra todos las propiedades del edificio
        virtual void mostrar();

        //PRE:
        //POS: Retorna el nombre del edificio
        string getNombre();

        //PRE:
        //POS:Retorna la cantidad de la piedra
        int getCantPiedra();

        //PRE:
        //POS:Retorna la cantidad de la madera
        int getCantMadera();

        //PRE:
        //POS:Retorna la cantidad del metal
        int getCantMetal();

        //PRE:
        //POS:Retorna la cantidad maxima permitida para construir
        int getMaxCantPermitidos();

};

#endif //EDIFICIO_H