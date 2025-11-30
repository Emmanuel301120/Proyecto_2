#ifndef ARBOLRB_H
#define ARBOLRB_H
#include "bstTemplates.h"
#include <string>
#include "Nodo.h"
using namespace std;

template <typename T>
class arbolRB : public bstTemplates<T>{
    public:

    arbolRB(){
        this->raiz = NULL;
    }

    Nodo<T>* minimo(Nodo<T>* it){
        while (it->left != NULL){
            it = it->left;
        }
        return it;
    }

    void transplantar(Nodo<T>* it, Nodo<T>* ajustar){
        if(it->padre == NULL){
            this->raiz = ajustar;
        }else if (it == it->padre->left){
            it->padre->left = ajustar;
        } else{
            it->padre->right = ajustar;
        }
        if(ajustar != NULL) ajustar->padre = it->padre;
    }

    void rotarIzquierda(Nodo<T>* it){
        Nodo<T>* ajustar = it->right;
        it->right = ajustar->left;
        if(ajustar->left != NULL) ajustar->left->padre = it;

        ajustar->padre = it->padre;
        if(it->padre == NULL){
            this->raiz = ajustar;
        }else if (it == it->padre->left){
            it->padre->left = ajustar;
        }else{
            it->padre->right = ajustar;
        }
        ajustar->left = it;
        it->padre = ajustar;
    }

    void rotarDerecha(Nodo<T>* it){
        Nodo<T>* ajustar = it->left;
        it->left = ajustar->right;
        if(ajustar->right != NULL) ajustar->right->padre = it;

        ajustar->padre = it->padre;
        if(it->padre == NULL){
            this->raiz = ajustar;
        }else if(it == it->padre->right){
            it->padre->right = ajustar;
        }else{
            it->padre->left = ajustar;
        }
        ajustar->right = it;
        it->padre = ajustar;
    }

    Nodo<T>* insert(T dato, string clave) override{
        Nodo<T>* nuevo = new Nodo<T>(dato, clave);
        nuevo->color = true;
        Nodo<T>* padreTemp = NULL;
        Nodo<T>* it = this->raiz;

        while (it != NULL){
            padreTemp = it;
            if (dato < it->dato){
                it = it->left;
            }else if(dato > it->dato){
                it = it->right;
            }else{
                it->dato = dato;
                delete nuevo;
                return it;
            }
        }
        nuevo->padre = padreTemp;
        if(padreTemp == NULL){
            this->raiz = nuevo;
        }else if(dato < padreTemp->dato){
            padreTemp->left = nuevo;
        }else{
            padreTemp->right = nuevo;
        }
        corregirInsercion(nuevo);
        return nuevo;
    } 

    void corregirInsercion(Nodo<T>* ajustar){
        while(ajustar->padre != NULL && ajustar->padre->color == true){
            if (ajustar->padre == ajustar->padre->padre->left){
                Nodo<T>* tio = ajustar->padre->padre->right;
                if(tio != NULL && tio->color == true){
                    ajustar->padre->color = false;
                    tio->color = false;
                    ajustar->padre->padre->color = true;
                    ajustar = ajustar->padre->padre;
                }else{
                    if (ajustar == ajustar->padre->right){
                        ajustar = ajustar->padre;
                        rotarIzquierda(ajustar);
                    }
                    ajustar->padre->color = false;
                    ajustar->padre->padre->color = true;
                    rotarDerecha(ajustar->padre->padre);
                }
            }else{
                Nodo<T>* tio = ajustar->padre->padre->left;
                if (tio != NULL && tio->color == true){
                    ajustar->padre->color = false;
                    tio->color = false;
                    ajustar->padre->padre->color = true;
                    ajustar = ajustar->padre->padre;
                }else{
                    if(ajustar == ajustar->padre->left){
                        ajustar = ajustar->padre;
                        rotarDerecha(ajustar);
                    }
                    ajustar->padre->color = false;
                    ajustar->padre->padre->color = true;
                    rotarIzquierda(ajustar->padre->padre);
                }
            }
        }
        this->raiz->color = false;
    }

    void eliminar(T dato) override{
        Nodo<T>* it = this->raiz;
        while (it != NULL && it->dato != dato){
            if(dato < it->dato) it = it->left;
            else it = it->right;
        }
        if(it == NULL) return;

        Nodo<T>* ajustar = it;
        bool colorOriginal = ajustar->color;
        Nodo<T>* reemplazo;

        if(it->left == NULL){
            reemplazo = it->right;
            transplantar(it, it->right);
        }else if   (it->right == NULL){
            reemplazo = it->left;
            transplantar(it, it->left);
        }else{
            Nodo<T>* sucesor = minimo(it->right);
            colorOriginal = sucesor->color;
            reemplazo = sucesor->right;
            if(sucesor->padre == it){
                if (reemplazo != NULL) reemplazo->padre = sucesor;
            }else{
                transplantar(sucesor, sucesor->right);
                sucesor->right = it->right;
                sucesor->right->padre = sucesor;
            }
            transplantar(it, sucesor);
            sucesor->left = it->left;
            sucesor->left->padre = sucesor;
            sucesor->color = it->color;
        }
        delete it;
        if (colorOriginal == false){
            corregirEliminacion(reemplazo);
        }
    }

    void corregirEliminacion(Nodo<T>* ajustar){
        while(ajustar != this->raiz && (ajustar == NULL || ajustar->color == false)){
            if(ajustar == ajustar->padre->left){
                moverHermanoIzquierdo(ajustar);
            }else{
                moverHermanoDerecho(ajustar);
            }
        }
        if (ajustar != NULL) ajustar->color = false;
    }

    void moverHermanoIzquierdo(Nodo<T>* ajustar){
        Nodo<T>* hermano = ajustar->padre->right;
        if (hermano != NULL && hermano->color == true){
            hermano->color = false;
            ajustar->padre->color = true;
            rotarIzquierda(ajustar->padre);
            hermano = ajustar->padre->right;
        }
        if((hermano->left == NULL || hermano->left->color == false) && (hermano->right == NULL || hermano->right->color == false)){
            hermano->color = true;
            ajustar = ajustar->padre;
        }else{
            if(hermano->right == NULL || hermano->right->color == false){
                if(hermano->left != NULL) hermano->left->color = false;
                hermano->color = true;
                rotarDerecha(hermano);
                hermano = ajustar->padre->right;
            }
            hermano->color = ajustar->padre->color;
            ajustar->padre->color = false;
            if(hermano->right != NULL) hermano->right->color = false;
            rotarIzquierda(ajustar->padre);
            ajustar = this->raiz;
        }
    }

    void moverHermanoDerecho(Nodo<T>* ajustar){
        Nodo<T>* hermano = ajustar->padre->left;
        if(hermano != NULL && hermano->color == true){
            hermano->color = false;
            ajustar->padre->color = true;
            rotarDerecha(ajustar->padre);
            hermano = ajustar->padre->left;
        }
        if((hermano->right == NULL || hermano->right->color == false) && (hermano->left == NULL || hermano->left->color == false)){
            hermano->color = true;
            ajustar = ajustar->padre;
        }else{
            if (hermano->left == NULL || hermano->left->color == false){
                if(hermano->right != NULL) hermano->right->color = false;
                hermano->color = true;
                rotarIzquierda(hermano);
                hermano = ajustar->padre->left;
            }
            hermano->color = ajustar->padre->color;
            ajustar->padre->color = false;
            if(hermano->left != NULL) hermano->left->color = false;
            rotarDerecha(ajustar->padre);
            ajustar = this->raiz;
        }
    }


    

   

};
#endif
