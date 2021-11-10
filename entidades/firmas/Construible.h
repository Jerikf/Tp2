#ifndef CONSTRUIBLE_H
#define CONSTRUIBLE_H

#include "Casillero.h"
#include "Edificio.h"
#include "Material.h"

class Construible : public Casillero
{
    private:
        Edificio* edificio;

    public:
        Construible();
        Construible(char,Edificio*);
        Construible(char);
        ~Construible();
        void mostrar();
        int construirEdificio(Edificio*);
        Edificio* getEdificio();
        Material* getMaterial();
        
};

#endif //CONSTRUIBLE_H