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
        void mostrar();
};

#endif //INACCESIBLE_H