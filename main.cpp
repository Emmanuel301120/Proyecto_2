#include "bstTemplates.h"
#include "arbolRB.h"
#include "Vehiculo.h"
#include "RBHash.h"

using namespace std;

int main(){
    int num1 = 10;
    int num2 = 20;
    int num3 = 30;
    int num4 = 40;
    int num5 = 50;
    int num6 = 60;
    int num7 = 70;
    int num8 = 80;
    int num9 = 90;
    int num10 = 100;
    int num11 = 110;
    int num12 = 120;
    
    cout<<"Pruebas para BST generico: "<< endl;

    cout<<endl<<"BST generico de enteros: "<< endl;
    bstTemplates<int>* bstInt = new bstTemplates<int>();
    bstInt->insert(num5,"");
    bstInt->insert(num6,"");
    bstInt->insert(num1,"");
    bstInt->insert(num7,"");
    bstInt->insert(num11,"");
    bstInt->insert(num2,"");
    bstInt->insert(num4,"");
    bstInt->insert(num8,"");
    bstInt->insert(num9,"");
    bstInt->insert(num12,"");
    bstInt->insert(num3,"");
    bstInt->insert(num10,"");
    bstInt->imprimir();
    cout<<endl;

    string cadena1 = "Arbol";
    string cadena2 = "Barril";
    string cadena3 = "Castillo";
    string cadena4 = "Dinosaurio";
    string cadena5 = "Electrico";
    string cadena6 = "Farol";
    string cadena7 = "Gato";
    string cadena8 = "Hijo";
    string cadena9 = "Isla";
    string cadena10 = "Juglar";
    string cadena11 = "Kilometro";
    string cadena12 = "Limon";

    cout<<endl<<"BST generico de Strings: "<< endl;
    bstTemplates<string>* bstStr = new bstTemplates<string>();
    bstStr->insert(cadena5,"");
    bstStr->insert(cadena6,"");
    bstStr->insert(cadena1,"");
    bstStr->insert(cadena7,"");
    bstStr->insert(cadena11,"");
    bstStr->insert(cadena2,"");
    bstStr->insert(cadena4,"");
    bstStr->insert(cadena8,"");
    bstStr->insert(cadena9,"");
    bstStr->insert(cadena12,"");
    bstStr->insert(cadena3,"");
    bstStr->insert(cadena10,"");
    bstStr->imprimir();
    cout<<endl;

    Vehiculo carro1 = Vehiculo("Rojo", 2, 4);
    Vehiculo carro2 = Vehiculo("Verde", 4, 5);
    Vehiculo carro3 = Vehiculo("Azul", 2, 5);
    Vehiculo carro4 = Vehiculo("Negro", 4, 4);
    Vehiculo carro5 = Vehiculo("Amarillo", 2, 4);
    Vehiculo carro6 = Vehiculo("Gris", 4, 5);
    Vehiculo carro7 = Vehiculo("Morado", 2, 5);
    Vehiculo carro8 = Vehiculo("Naranja", 4, 4);
    Vehiculo carro9 = Vehiculo("Blanco", 2, 4);
    Vehiculo carro10 = Vehiculo("Cafe", 4, 5);
    Vehiculo carro11 = Vehiculo("Celeste", 2, 5);
    Vehiculo carro12 = Vehiculo("Turquesa", 4, 4);

    cout<<endl<<"BST generico de Vehiculos: "<< endl;
    bstTemplates<Vehiculo>* bstTemp = new bstTemplates<Vehiculo>();
    bstTemp->insert(carro1,"");
    bstTemp->insert(carro2,"");
    bstTemp->insert(carro3,"");
    bstTemp->insert(carro4,"");
    bstTemp->insert(carro5,"");
    bstTemp->insert(carro6,"");
    bstTemp->insert(carro7,"");
    bstTemp->insert(carro8,"");
    bstTemp->insert(carro9,"");
    bstTemp->insert(carro10,"");
    bstTemp->insert(carro11,"");
    bstTemp->insert(carro12,"");
    bstTemp->imprimir();
    cout<<endl;

    cout<<"Pruebas para RBT generico: "<< endl;

    cout<<endl<<"RBT generico de enteros: "<< endl;
    arbolRB<int> rbtInt = arbolRB<int>();
    rbtInt.insert(num1,"Brazil");
    rbtInt.insert(num2,"Argentina");
    rbtInt.insert(num3,"Huruguai");
    rbtInt.insert(num4,"Chile");
    rbtInt.insert(num5,"Colombia");
    rbtInt.insert(num6,"Guatemala");
    rbtInt.insert(num7,"CostaTica");
    rbtInt.insert(num8,"Nicaragua");
    rbtInt.insert(num9,"Panama");
    rbtInt.insert(num10,"Salvador");
    rbtInt.insert(num11,"Ecuador");
    rbtInt.insert(num12,"Cuba");
    rbtInt.imprimirPorNiveles();

    cout<<endl<<"RBT generico de Strings: "<< endl;
    arbolRB<string> rbtStrin = arbolRB<string>();
    rbtStrin.insert(cadena1,"Brazil");
    rbtStrin.insert(cadena2,"Argentina");
    rbtStrin.insert(cadena3,"Huruguai");
    rbtStrin.insert(cadena4,"Chile");
    rbtStrin.insert(cadena5,"Colombia");
    rbtStrin.insert(cadena6,"Guatemala");
    rbtStrin.insert(cadena7,"CostaTica");
    rbtStrin.insert(cadena8,"Nicaragua");
    rbtStrin.insert(cadena9,"Panama");
    rbtStrin.insert(cadena10,"Salvador");
    rbtStrin.insert(cadena11,"Ecuador");
    rbtStrin.insert(cadena12,"Cuba");
    rbtStrin.imprimirPorNiveles();

    cout<<endl<<"RBT generico de Veiculos: "<< endl;
    arbolRB<Vehiculo> rbtVehivulos = arbolRB<Vehiculo>();
    rbtVehivulos.insert(carro1,"Brazil");
    rbtVehivulos.insert(carro2,"Argentina");
    rbtVehivulos.insert(carro3,"Huruguai");
    rbtVehivulos.insert(carro4,"Chile");
    rbtVehivulos.insert(carro5,"Colombia");
    rbtVehivulos.insert(carro6,"Guatemala");
    rbtVehivulos.insert(carro7,"CostaTica");
    rbtVehivulos.insert(carro8,"Nicaragua");
    rbtVehivulos.insert(carro9,"Panama");
    rbtVehivulos.insert(carro10,"Salvador");
    rbtVehivulos.insert(carro11,"Ecuador");
    rbtVehivulos.insert(carro12,"Cuba");
    rbtVehivulos.imprimirPorNiveles();
}
