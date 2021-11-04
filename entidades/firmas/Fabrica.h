#ifndef FABRICA_H
#define FABRICA_H

#include "Edificio.h"

class Fabrica : public Edificio
{
    private:
        /* data */

    public:
        Fabrica(string, int, int, int, int);
        ~Fabrica();
        void mostrar();
};

#endif //FABRICA_H