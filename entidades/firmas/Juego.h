#ifndef JUEGO_H
#define JUEGO_H
#include <stdbool.h>
#include <string>

#include "../../estructura/Vect.h"
#include "../../accesoDatos/modelo/Datos.h"
#include "Mapa.h"
#include "Edificio.h"
#include "Material.h"

using namespace std;

class Juego
{
    private:
        Datos* datos;
        Vect<Edificio>* edificios;
        Vect<Material>* materiales;
        Mapa* mapa;

        //PRE: RECIBE UN NOMBRE DE EDIFCIO
        //POS: DEVUELVE UN VECTOR DE COORDENAS QUE SE BUSCARON EN EL MAPA, EN CASO DE NO HABER NINGÚN EDIFICIO CON DICHO NOMBRE DEVUELVE NULL
        Vect<Coordenada>* obtenerCoordenadas(string);
    public:
        Juego(Datos*, Vect<Edificio>*, Vect<Material>*);
        ~Juego();
        void inicializarCargadoDatos();
        void mostrarMenu();
        void listarEdificiosConstruidos();
        void listarTodosLosEdificios();
        void mostrarInventario();

};

#endif //JUEGO_H