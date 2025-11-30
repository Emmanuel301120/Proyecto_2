#ifndef NODO_H
#define NODO_H
#include <string>
#include "arbolRB.h"
#include "searchDatos.h"
using namespace std;

template <typename T>
class Nodo{
    public:
    //bool color = false; //Nodos negros = false Nodos rojos = true
    T dato;
    string clave;
    Nodo<T>* left;
    Nodo<T>* right;
    

    Nodo(T& dato, string clave){
        this->dato = dato;
        this->right = nullptr;
        this->left = nullptr;
        this->clave = clave;
    }

    Nodo(T& dato){
        this->dato = dato;
        this->right = nullptr;
        this->left = nullptr;
        clave = "";
    }


    

    string toString(){
        stringstream ss;
        ss<<dato;
        return ss.str();
    }

    friend ostream& operator<<(ostream& os, Nodo& nd ){
    os << nd.toString();
    return os;
  }
};
