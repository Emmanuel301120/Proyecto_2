#include "Vehiculo.h"
#include <sstream>
#include <iostream>

    Vehiculo::Vehiculo(){
        this->color = "Default";
        this->ruedas = 0;
        this->puertas = 0;
    }

    Vehiculo::Vehiculo(string color, int ruedas, int puertas){
        this->color = color;
        this->ruedas = ruedas;
        this->puertas = puertas;
    }

    bool Vehiculo::operator<(const Vehiculo& v) const{
        return this->color < v.color;
    }
    
    bool Vehiculo::operator==(const Vehiculo& v) const{
        return this->color == v.color;
    }

    bool Vehiculo::operator!=(const Vehiculo& v) const{
        return this->color != v.color;
    }


    bool Vehiculo::operator>(const Vehiculo& v) const{
        if(this->color>v.color){
            return true;
        }else{
            return false;
        }
    }

    string Vehiculo::toString() const{
        stringstream ss;
        ss<<"Color: "<<color<<"-Ruedas: "<<ruedas<<"-Puertas: "<<puertas;
        return ss.str();
    }

    ostream& operator<<(ostream& os, const Vehiculo& car){
        os<<car.toString();
        return os;
    }
