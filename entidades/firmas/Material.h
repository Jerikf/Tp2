#ifndef MATERIAL_H
#define MATERIAL_H
#include <string>
using namespace std;

class Material
{
    private:
        string nombre;
        int cantidad;

    public:
        Material(string, int);
        ~Material();
        void mostrar();
};

#endif //MATERIAL_H