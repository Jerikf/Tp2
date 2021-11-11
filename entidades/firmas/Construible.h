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

        //PRE:
        //POS: Demuele un edificio(instancia el puntero de edificio en null) retornando el edificio apuntado
        Edificio* demolerEdificio();
        
};

#endif //CONSTRUIBLE_H