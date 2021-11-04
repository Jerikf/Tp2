#ifndef OBELISCO_H
#define OBELISCO_H

#include "Edificio.h"

class Obelisco : public Edificio
{
    private:
        /* data */

    public:
        Obelisco(string, int, int, int, int);
        ~Obelisco();
        void mostrar();
};

#endif //OBELISCO_H