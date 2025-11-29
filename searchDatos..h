#ifndef SEARCHDATOS_H
#define SEARCHDATOS_H
#include <string>
#include "arbolRB.h"
using namespace std;

template<typename T>
struct searchDatos{
    public:
    Nodo<T>* nodoEncontrado;
    bool encontrado = false;
    searchDatos(){
        nodoEncontrado = nullptr;
    }
};
#endif
