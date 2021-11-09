#ifndef DATOS_H
#define DATOS_H
#include <stdbool.h>
#include <string>

#include "../../entidades/firmas/Coordenada.h"
#include "../../estructura/Vect.h"
#include "../../entidades/firmas/Mapa.h"
#include "../../entidades/firmas/Edificio.h"
#include "../../entidades/firmas/PlantaElectrica.h"
#include "../../entidades/firmas/Aserradero.h"
#include "../../entidades/firmas/Obelisco.h"
#include "../../entidades/firmas/Fabrica.h"
#include "../../entidades/firmas/Escuela.h"
#include "../../entidades/firmas/Mina.h"
#include "../../entidades/firmas/Material.h"

#include "../../entidades/firmas/Casillero.h"
#include "../../entidades/firmas/Construible.h"
#include "../../entidades/firmas/Transitable.h"
#include "../../entidades/firmas/Inaccesible.h"

using namespace std;


class Datos
{
    private:
        string nombreArchivoEdificios;
        string nombreArchivoMateriales;
        string nombreArchivoMapa;
        string nombreArchivoUbicaciones;
        Coordenada extraerCoordenada(string,string);
        
    public:
        Datos(string,string,string, string);
        ~Datos();

        void cargarDatosEdificios(Vect<Edificio>* datos);
        void cargarDatosMateriales(Vect<Material>* materiales);
        void cargarDatosMapa(Mapa** mapa);
        void cargarDatosUbicaciones(Mapa* mapa, Vect<Edificio>*);

        void guardarDatosMateriales(Vect<Material>* materiales);
        void gurdarDatosEdificios(Vect<Edificio>* edificios);
        void guardarDatosMapa(Mapa* mapa);
        void guardarDatosUbicaciones(Mapa* mapa);

        

};

#endif //DATOS_H