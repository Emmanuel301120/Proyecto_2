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

 /*
    void search(Nodo* raiz, string key, searchDatos& sd){
        if(raiz == NULL || sd.encontrado)return;
        if(raiz->clave == key){
            sd.nodoEncontrado = raiz;
            sd.encontrado = true;
        }
        search(raiz->left, key, sd);
        search(raiz->right, key, sd);
    }*/


    void eliminar(T dato){
        if(raiz == NULL) return;
        Nodo* it = raiz;
        Nodo* padre = nullptr;
        char hijo = 'r';
    
        while(it != nullptr && it->dato != dato){
            padre = it;
            if(dato < it->dato){
                it = it->left;
                hijo = 'l';
            }else{
                it = it->right;
                hijo = 'r';
            }
        }
        if(it == nullptr) return; 
    
        if(it->right == NULL && it->left == NULL){
            if(padre != nullptr){
                if(hijo == 'l'){
                    delete padre->left; padre->left = NULL;
                }else{
                    delete padre->right; padre->right = NULL;
                }
            }else{
                delete raiz; raiz = NULL;
            }
        }

        else if(it->right == NULL && it->left != NULL && it->left->left == NULL && it->left->right == NULL){
            it->dato = it->left->dato;
            delete it->left;
            it->left = NULL;
        }

        else if(it->right != NULL && it->left == NULL && it->right->left == NULL && it->right->right == NULL){
            it->dato = it->right->dato;
            delete it->right;
            it->right = NULL;
        }

        else if(it->right != NULL && it->left != NULL){
            Nodo* eliminar = it;
            Nodo* padreSucesor = it;
            it = it->right;
            while(it->left != NULL){
                padreSucesor = it;
                it = it->left;
            }

            eliminar->dato = it->dato;
    
            if(padreSucesor->left == it){
                padreSucesor->left = it->right;
            }else{
                padreSucesor->right = it->right;
            }
            delete it;
        }
    }
