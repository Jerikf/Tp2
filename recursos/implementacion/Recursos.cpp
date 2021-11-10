#include "../firmas/Recursos.h"
#include <iostream>

Recurso::Recurso(){}
Recurso::~Recurso(){}

string Recurso::convertirAMayuscula(string cadena){
    string cadenaNueva = "";
	for(int pos = 0; pos < (int)cadena.size(); pos++)
		cadenaNueva += (char)toupper(cadena[pos]);
	return cadenaNueva;
}

