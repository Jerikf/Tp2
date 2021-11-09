#ifndef COORDENADA_H
#define COORDENADA_H

using namespace std;

class Coordenada
{
    private:
        int fila;
        int columna;

    public:
        Coordenada(int, int);
        Coordenada();
        ~Coordenada();
        void mostrar();
        int getFila();
        int getColumna();
        void setFila(int);
        void setColumna(int);
};

#endif //COORDENADA_H