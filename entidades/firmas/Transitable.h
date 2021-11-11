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

        //PRE:
        //POS: Muestra el mensaje que es otro casillero y retorna NULL
        Edificio* demolerEdificio();
        void mostrar();
};

#endif //TRANSITABLE_H