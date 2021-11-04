#ifndef EDIFICIO_H
#define EDIFICIO_H
#include <stdbool.h>
#include <string>

using namespace std;

class Edificio
{
    protected:
        string nombre;
        int cantPiedra;
        int cantMadera;
        int cantMetal;
        int maxCantPermitidos;

    public:
        Edificio(string, int, int, int, int);
        //Edificio();
        virtual ~Edificio();
        virtual void mostrar()=0;
};

#endif //EDIFICIO_H