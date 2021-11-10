#ifndef TRANSITABLE_H
#define TRANSITABLE_H

#include "Casillero.h"
#include "Material.h"


class Transitable : public Casillero
{
    private:
        Material* material;
    public:
        Transitable();
        Transitable(char,Material*);
        Transitable(char);
        ~Transitable();
        Material* getMaterial();
        void setMaterial(Material*);
        int construirEdificio(Edificio*);
        Edificio* getEdificio();
        void mostrar();
};

#endif //TRANSITABLE_H