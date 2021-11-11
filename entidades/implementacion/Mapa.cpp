#include "../firmas/Mapa.h"
#include <iostream>
Mapa::Mapa(int cantFilas, int cantColumnas){
    this->cantFilas = cantFilas;
    this->cantColumnas = cantColumnas;

    //Reservo memoria para las Filas
    this->casilleros = new Casillero**[cantFilas];
    
    //Reservo memoria para las Columnas
    for(int pos = 0; pos < cantFilas; pos++){
        this->casilleros[pos] = new Casillero*[cantColumnas];
    }

    //Instancio en NUll el contenido || sirve para evitar los errores SUMMARY de valgrind

    for(int i = 0; i < this->cantFilas; i++){
        for(int j = 0; j < this->cantColumnas; j++){
                this->casilleros[i][j] = NULL;
        }
    }
}

Mapa::~Mapa(){
    for(int fila = 0; fila < this->cantFilas; fila++){
        for(int col = 0; col < this->cantColumnas; col++){
            if(casilleros[fila][col]) // en caso tenga algùn casillero que no sea NULL
                delete this->casilleros[fila][col]; //Libero memoria de cada uno de los casilleros guardados
        }
        delete[] this->casilleros[fila]; // Libero memoria de fila
    }
    delete[] this->casilleros; // libero la "matriz" casilleros
}

void Mapa::agregarCasillero(Casillero* casillero, Coordenada coordenada){
    if(coordenada.getFila() >= this->cantFilas || coordenada.getColumna() >= this->cantColumnas){
        cout << "\n\n ERROR --> SE INGRESÒ UNA COORDENADA FUERA DEL RANGO DEL MAPA" << endl;
    }else if(casilleros[coordenada.getFila()][coordenada.getColumna()]){
        cout << "\n\n ERROR --> NO SE PUEDE AGREGAR EL CASILLERO PORQUE ESTÀ OCUPADO EL LUGAR" << endl;
    }else{
        casilleros[coordenada.getFila()][coordenada.getColumna()] = casillero;
    }
}

Casillero* Mapa::getCasillero(Coordenada coordenada){
    if(coordenada.getFila() >= this->cantFilas || coordenada.getColumna() >= this->cantColumnas)
        return NULL;
    return this->casilleros[coordenada.getFila()][coordenada.getColumna()];
}

int Mapa::getCantFilas(){
    return this->cantFilas;
}

int Mapa::getCantColumnas(){
    return this->cantColumnas;
}

//TODO-->Modificar para que muestre como corresponde
void Mapa::mostrar(){
    for(int i = 0; i < this->cantFilas; i++){
        for(int j = 0; j < this->cantColumnas; j++){
            if(this->casilleros[i][j]){
                this->casilleros[i][j]->mostrar();
            }else{
                cout << "--contenido vacìo -----" << endl;
            }
                
        }
    }
}