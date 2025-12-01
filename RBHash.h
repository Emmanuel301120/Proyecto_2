#ifndef RBHASH_H
#define RBHASH_H
#include <string>
#include "arbolRB.h"
#include "searchDatos.h"
#include "Nodo.h"
using namespace std;

template <typename T>
class RBHash{
    T dato;
    
    public:
    arbolRB<T>* arbol;

    RBHash(){}
    RBHash(T tipo){
        dato = tipo;
    }

    T& operator[](string clave){
        searchDatos<T> sd;
        (arbol.search(arbol.raiz, clave, sd));
        if(sd.encontrado){
            return (sd.nodoEncontrado)->dato;
        }else{
            Nodo<T>* insertado = arbol.insert(T(), clave);
            return insertado->dato;
        }

    }


};
#endif
