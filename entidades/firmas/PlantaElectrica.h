#ifndef PLANTAELECTRICA_H
#define PLANTAELECTRICA_H

#include "Edificio.h"

class PlantaElectrica : public Edificio
{
    private:
        /* data */

    public:

        //PRE:Recibe un nombre, cantidades de piedra, madera, metal y un maximo permitido
        //POS:Construye la planta Electrica, pasando los argumento a la clase padre Edificio
        PlantaElectrica(string, int, int, int, int);

        //PRE:
        //POS:destructor
        ~PlantaElectrica();

        //PRE:
        //POS:Llama al mostrar del padre(que tiene toda la info del edificio) y además muestra que no brinda material
        void mostrar();
};

#endif //PLANTAELECTRICA_H