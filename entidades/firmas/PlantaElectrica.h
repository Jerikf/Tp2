#ifndef PLANTAELECTRICA_H
#define PLANTAELECTRICA_H

#include "Edificio.h"

class PlantaElectrica : public Edificio
{
    private:
        /* data */

    public:
        PlantaElectrica(string, int, int, int, int);
        ~PlantaElectrica();
        void mostrar();
};

#endif //PLANTAELECTRICA_H