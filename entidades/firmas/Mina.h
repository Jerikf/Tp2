#ifndef MINA_H
#define MINA_H

#include "Edificio.h"

class Mina : public Edificio
{
    private:
        /* data */

    public:

        //PRE:Recibe un nombre, cantidades de piedra, madera, metal y un maximo permitido
        //POS:Construye la fabrica, pasando los argumento a la clase padre Edificio
        Mina(string, int, int, int, int);

        //PRE:
        //POS:destructor
        ~Mina();

        //PRE:
        //POS:Llama al mostrar del padre(que tiene toda la info del edificio) y además muestra que brinda material
        void mostrar();
};

#endif //MINA_H