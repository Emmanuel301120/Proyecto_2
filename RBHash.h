#ifndef RBHASH_H
#define RBHASH_H
#include <string>
#include "arbolRB.h"
#include "searchDatos.h"
using namespace std;

template <typename T>
class RBHash{
    T dato;
    
    public:
    bool encontrado = false;
    arbolRB<T>* arbol;

    RBHash(){}
    RBHash(T tipo){
        dato = tipo;
    }

    T& operator[](string clave){
        searchDatos sd;
        (arbol.search(arbol.raiz, clave, sd));
        if(sd.encontrado){
            return (sd.nodoEncontrado)->dato;
        }else{
            Nodo<T>* nuevo = new Nodo(T(), clave);
            arbol.insert(nuevo);
            return nuevo->dato;
        }

    }


};
#endif

