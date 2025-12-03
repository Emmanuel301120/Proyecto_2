#ifndef VEHICULO_H
#define VEHICULO_H
#include <string>
#include <iostream>
using namespace std;

class Vehiculo{
    public:
    string color;
    int ruedas;
    int puertas;

    Vehiculo();
    Vehiculo(string color, int ruedas, int puertas);

    bool operator<(const Vehiculo& v) const;
    
    bool operator==(const Vehiculo& v) const;

    bool operator!=(const Vehiculo& v) const;

    bool operator>(const Vehiculo& v) const;

    string toString() const;

    friend ostream& operator<<(ostream& os, const Vehiculo& car);
};
#endif
