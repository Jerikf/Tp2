#ifndef ASERRADERO_H
#define ASERRADERO_H

#include "Edificio.h"

class Aserradero : public Edificio
{
    private:
        /* data */

    public:
        Aserradero(string, int, int, int, int);
        ~Aserradero();
        void mostrar();
};

#endif //ASERRADERO_H