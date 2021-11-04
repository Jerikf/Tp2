#ifndef MINA_H
#define MINA_H

#include "Edificio.h"

class Mina : public Edificio
{
    private:
        /* data */

    public:
        Mina(string, int, int, int, int);
        ~Mina();
        void mostrar();
};

#endif //MINA_H