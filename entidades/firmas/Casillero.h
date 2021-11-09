#ifndef CASILLERO_H
#define CASILLERO_H
#include <stdbool.h>
#include <string>

#include "Edificio.h"
#include "Material.h"

using namespace std;

class Casillero
{
    protected:
        char tipo;
    public:
        Casillero(char);
        Casillero();
        virtual ~Casillero();
        virtual void mostrar()=0;
        virtual void construirEdificio(Edificio*)=0;
        virtual Edificio* getEdificio()=0;
        virtual Material* getMaterial()=0;
        void mostrarTipo();
        char getTipo();
        void setTipo(char);
};

#endif //CASILLERO_H