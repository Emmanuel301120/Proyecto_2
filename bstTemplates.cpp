#include <iostream>
#include <sstream>

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

template <typename T>
class bstGenerico{
    public:
    Nodo<T>* raiz;

    bstGenerico(){
        this->raiz = nullptr;
    }

    bstGenerico(T dato){
        this->raiz = new Nodo<T>(dato);
    }

    void insert(T dato){
        if(raiz==nullptr){
            raiz = new Nodo<T>(dato);
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
        }
    }

    void eliminar(T dato){
        if(raiz == NULL) return NULL;
        Nodo* it = raiz;
        Nodo* padre;
        char hijo = 'r';
        while(it->dato != dato){
            padre = it;
            if(dato < it->dato){
                it = it->left;
                hijo = 'l';
            }else{
                it = it->right;
                hijo = 'r';
            }
        }
        if(it->right == NULL && it->left == NULL){
            if(hijo == 'l'){
                delete padre->left; padre->left = NULL;
            }else{
                delete padre->right; padre->right = NULL;
            } 
        }
        else if(it->right == NULL && it->left != NULL && it->left->left == NULL && it->left->right-> == NULL){
            it->dato = it->left->dato;
            delete it->left;
            it->left = NULL;
        }
        else if(it->right != NULL && it->left == NULL && it->right->left == NULL && it->right->right-> == NULL){
            it->dato = it->right->dato;
            delete it->right;
            it->right = NULL;
        }else if(it->right != NULL && it->left != NULL){
            Nodo* eliminar = it;
            it = it->right;
            while(it->left != NULL){
                padre = it;
                it = it->left;
            }
            eliminar->dato = it->dato;
            delete padre->left;
            padre->left = NULL;
        }
    }

    void imprimir(){
        imprimir(this->raiz);
    }

    void imprimir(Nodo<T>* inicio){
        if(inicio==nullptr){
            return;
        }else{
            Nodo<T>* temp = inicio;
            imprimir(temp->left);
            cout<<temp->dato<<"//";
            imprimir(temp->right);
        }
    }

};

class Vehiculo{
    public:
    string color;
    int ruedas;
    int puertas;

    Vehiculo(){
        color = "";
        ruedas = 0;
        puertas = 0;
    }

    Vehiculo(string color, int ruedas, int puertas){
        this->color = color;
        this->ruedas = ruedas;
        this->puertas = puertas;
    }

    bool operator>(Vehiculo& v){
        if(this->color>v.color){
            return true;
        }else{
            return false;
        }
    }

    string toString(){
        stringstream ss;
        ss<<"Color: "<<color<<" - Ruedas: "<<ruedas<<" - Puertas: "<<puertas;
        return ss.str();
    }

    friend ostream& operator<<(ostream& os, Vehiculo& car){
        os<<car.toString();
        return os;
    }
};

int main(){
    int num1 = 50;
    int num2 = 60;
    int num3 = 30;
    int num4 = 40;

    bstGenerico<int>* bstInt = new bstGenerico<int>();
    bstInt->insert(num1);
    bstInt->insert(num2);
    bstInt->insert(num3);
    bstInt->insert(num4);
    bstInt->imprimir();
    cout<<endl;

    string cadena1 = "1Hola";
    string cadena2 = "2Hola";
    string cadena3 = "4Hola";
    string cadena4 = "3Hola";
    
    bstGenerico<string>* bstStr = new bstGenerico<string>();
    bstStr->insert(cadena1);
    bstStr->insert(cadena2);
    bstStr->insert(cadena3);
    bstStr->insert(cadena4);
    bstStr->imprimir();
    cout<<endl;

    Vehiculo carro1 = Vehiculo("Rojo", 2, 4);
    Vehiculo carro2 = Vehiculo("Verde", 4, 5);
    Vehiculo carro3 = Vehiculo("Azul", 2, 5);
    Vehiculo carro4 = Vehiculo("Negro", 4, 4);

    bstGenerico<Vehiculo>* bstTemp = new bstGenerico<Vehiculo>();
    bstTemp->insert(carro1);
    bstTemp->insert(carro2);
    bstTemp->insert(carro3);
    bstTemp->insert(carro4);

    bstTemp->imprimir();
    cout<<endl;
}
