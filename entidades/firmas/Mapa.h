#ifndef MAPA_H
#define MAPA_H

#include "Casillero.h"
#include "Coordenada.h"

class Mapa
{
    private:
        int cantFilas;
        int cantColumnas;
        Casillero*** casilleros;
    public:
        Mapa(int,int);
        ~Mapa();
        void mostrar();
        void agregarCasillero(Casillero*,Coordenada);
        Casillero* getCasillero(Coordenada);
        int getCantFilas();
        int getCantColumnas();
    };




#endif //MAPA_H