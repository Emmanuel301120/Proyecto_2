#ifndef BSTTEMPLATES_H
#define BSTTEMPLATES_H
#include <iostream>
#include <sstream>

#include "Nodo.h"
#include "searchDatos.h"


using namespace std;

template <typename T>
class NodoCola {
public:
    Nodo<T>* dato;
    NodoCola<T>* siguiente;

    NodoCola(Nodo<T>* dato){
        this->dato = dato; 
        this->siguiente = nullptr;
    }
};

template <typename T>
class Cola {
private:
    NodoCola<T>* inicio;
    NodoCola<T>* fin;

public:
    Cola(){
        this->inicio = nullptr; 
        this->fin = nullptr;
    }

    void push(Nodo<T>* dato) {
        NodoCola<T>* nuevo = new NodoCola<T>(dato);
        if (!fin) {
            inicio = fin = nuevo;
        } else {
            fin->siguiente = nuevo;
            fin = nuevo;
        }
    }

    Nodo<T>* pop() {
        if (!inicio){
            return nullptr;
        }
        NodoCola<T>* temp = inicio;
        Nodo<T>* dato = temp->dato;
        inicio = inicio->siguiente;
        if (!inicio){
          fin = nullptr;  
        } 
        delete temp;
        return dato;
    }

    bool empty() const {
        if(inicio == nullptr){
            return true;
        }
    }

    int length(){
    int contador = 0;
    NodoCola<T>* actual = inicio;
    while (actual != nullptr) {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}
};

template <typename T>
class bstTemplates{
    public:
    Nodo<T>* raiz;

    bstTemplates(){
        this->raiz = nullptr;
    }

    bstTemplates(T dato){
        this->raiz = new Nodo<T>(dato, "");
    }

    virtual Nodo<T>* insert(T dato, string clave){
        if(raiz==nullptr){
            raiz = new Nodo<T>(dato, clave);
            return raiz;
        }else{
            Nodo<T>* temp = raiz;
            Nodo<T>* padre = nullptr;
            while (temp != nullptr){
                if(dato>temp->dato){
                    padre = temp;
                    temp = temp->right;
                    //cout<<dato<<"D"<<endl;
                }else{
                    padre = temp;
                    temp = temp->left;
                    //cout<<dato<<"I"<<endl;
                }
            }
            temp = new Nodo<T>(dato);
            if(temp->dato>padre->dato){
                padre->right = temp;
            }else{
                padre->left = temp;
            }    
            return temp;
        }
    }

    void search(Nodo<T>* raiz, string key, searchDatos<T>& sd){
        if(raiz == NULL || sd.encontrado)return;
        if(raiz->clave == key){
            sd.nodoEncontrado = raiz;
            sd.encontrado = true;
        }
        search(raiz->left, key, sd);
        search(raiz->right, key, sd);
    }

    virtual void eliminar(T dato){
        if(raiz == NULL) return;
        Nodo<T>* it = raiz;
        Nodo<T>* padre = nullptr;
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
            Nodo<T>* eliminar = it;
            Nodo<T>* padreSucesor = it;
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



    void imprimir(){
        inorder(this->raiz);
    }

    void inorder(Nodo<T>* inicio){
        if(inicio==nullptr){
            return;
        }else{
            Nodo<T>* temp = inicio;
            inorder(temp->left);
            cout<<temp->dato<<"//";
            inorder(temp->right);
        }
    }

    void preorder(Nodo<T>* inicio){
        if(inicio==nullptr){
            return;
        }else{
            Nodo<T>* temp = inicio;
            cout<<temp->dato<<"//";
            preorder(temp->left);
            preorder(temp->right);
        }
    }

    void postorder(Nodo<T>* inicio){
        if(inicio==nullptr){
            return;
        }else{
            Nodo<T>* temp = inicio;
            postorder(temp->left);
            postorder(temp->right);
            cout<<temp->dato<<"//";
        }
    }

    void imprimirPorNiveles(){
    if (raiz==nullptr) return;

    Cola<T> cola;
    cola.push(raiz);

    while (!(cola.empty())){
        int numNiveles = cola.length();

        for (int i = 0; i < numNiveles; ++i) {
            Nodo<T>* actual = cola.pop();
            cout << actual->dato << "//";

            if (actual->left){
                cola.push(actual->left);
            }
            if (actual->right){
                cola.push(actual->right);
            }
        }

        cout<<endl;
    }
    }

};

#endif
