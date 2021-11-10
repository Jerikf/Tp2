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
        virtual void mostrar();
        string getNombre();
        int getCantPiedra();
        int getCantMadera();
        int getCantMetal();
        int getMaxCantPermitidos();

};

#endif //EDIFICIO_H