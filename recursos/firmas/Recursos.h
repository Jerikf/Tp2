#ifndef RECURSOS_H
#define RECURSOS_H
#include <stdbool.h>
#include <string>


using namespace std;

class Recurso
{
    private:

    public:

        //PRE:
		//POS:Contruye el Recurso vacio
        Recurso();

        //PRE:
		//POS: Destructor
        ~Recurso();

        //PRE: Recibe una cadena
		//POS: Convirete la cadena recibida en mayúscula y lo devuelve
        string convertirAMayuscula(string);
  
};

#endif //RECURSOS_H