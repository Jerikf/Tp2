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