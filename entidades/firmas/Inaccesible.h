#ifndef INACCESIBLE_H
#define INACCESIBLE_H

#include "Casillero.h"

class Inaccesible : public Casillero
{
    private:

    public:
        Inaccesible();
        Inaccesible(char);
        ~Inaccesible();
        int construirEdificio(Edificio*);
        Edificio* getEdificio();
        Material* getMaterial();

        //PRE:
        //POS: Muestra el mensaje que es otro casillero y retorna NULL
        Edificio* demolerEdificio();
        void mostrar();
};

#endif //INACCESIBLE_H