#ifndef ESCUELA_H
#define ESCUELA_H

#include "Edificio.h"

class Escuela : public Edificio
{
    private:
        /* data */

    public:
        Escuela(string, int, int, int, int);
        ~Escuela();
        void mostrar();
};

#endif //ESCUELA_H