#include "bstTemplates.h"
#include "Vehiculo.h"
#include "RBHash.h"

using namespace std;

int main(){
    int num1 = 50;
    int num2 = 60;
    int num3 = 30;
    int num4 = 40;

    bstTemplates<int>* bstInt = new bstTemplates<int>();
    bstInt->insert(num1,"");
    bstInt->insert(num2,"");
    bstInt->insert(num3,"");
    bstInt->insert(num4,"");
    bstInt->imprimirPorNiveles();
    cout<<endl;

    string cadena1 = "1Hola";
    string cadena2 = "2Hola";
    string cadena3 = "4Hola";
    string cadena4 = "3Hola";

    bstTemplates<string>* bstStr = new bstTemplates<string>();
    bstStr->insert(cadena1,"");
    bstStr->insert(cadena2,"");
    bstStr->insert(cadena3,"");
    bstStr->insert(cadena4,"");
    bstStr->imprimirPorNiveles();
    cout<<endl;

    Vehiculo carro1 = Vehiculo("Rojo", 2, 4);
    Vehiculo carro2 = Vehiculo("Verde", 4, 5);
    Vehiculo carro3 = Vehiculo("Azul", 2, 5);
    Vehiculo carro4 = Vehiculo("Negro", 4, 4);

    bstTemplates<Vehiculo>* bstTemp = new bstTemplates<Vehiculo>();
    bstTemp->insert(carro1,"");
    bstTemp->insert(carro2,"");
    bstTemp->insert(carro3,"");
    bstTemp->insert(carro4,"");
    bstTemp->imprimirPorNiveles();
    cout<<endl;

}
