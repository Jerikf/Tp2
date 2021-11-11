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

        //PRE: Recibe el nombre de un edificio
        //POS: Devuelve un vector de coordenadas que se bucaron en el mapa, en caso de no haber ningún edificio con dicho nombre devuelve null
        Vect<Coordenada>* obtenerCoordenadas(string);

        //PRE: Recibe el nombre de un material
        //POS: Devuelve el material en caso de encontrarse en el vect de materiales, caso contrario devuelve NULL
        Material* obtenerMaterial(string);

        //PRE: Recibe el nombre de un edificio
        //POS: Devuelve el edificio en caso de encontrarse en el vect de edificios, caso contrario devuelve NULL
        Edificio* obtenerEdificio(string);
        
    public:
        Juego(Datos*, Vect<Edificio>*, Vect<Material>*);
        ~Juego();
        void inicializarCargadoDatos();
        void mostrarMenu();
        void listarEdificiosConstruidos();
        void listarTodosLosEdificios();
        void mostrarInventario();
        void construirEdificioPorNombre(string,Coordenada);
        void demolerEdificioPorCoordenada(Coordenada);

};

#endif //JUEGO_H