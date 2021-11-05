#ifndef DATOS_H
#define DATOS_H
#include <stdbool.h>
#include <string>

#include "../../estructura/Vect.h"
#include "../../entidades/firmas/Edificio.h"
#include "../../entidades/firmas/PlantaElectrica.h"
#include "../../entidades/firmas/Aserradero.h"
#include "../../entidades/firmas/Obelisco.h"
#include "../../entidades/firmas/Fabrica.h"
#include "../../entidades/firmas/Escuela.h"
#include "../../entidades/firmas/Mina.h"
#include "../../entidades/firmas/Material.h"
using namespace std;


class Datos
{
    protected:
        string nombreArchivoEdificios;
        string nombreArchivoMateriales;
        
    public:
        Datos(string,string);
        ~Datos();

        void cargarDatosEdificios(Vect<Edificio>* datos);
        void cargarDatosMateriales(Vect<Material>* materiales);

        void guardarDatosMateriales(Vect<Material>* materiales);
        void gurdarDatosEdificios(Vect<Edificio>* edificios);
        
};

#endif //DATOS_H