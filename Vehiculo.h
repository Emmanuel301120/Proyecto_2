#ifndef VEHICULO_H
#define VEHICULO_H
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

    bool operator<(const Vehiculo& v) const {
        return this->color < v.color;
    }
    
    bool operator==(const Vehiculo& v) const {
        return this->color == v.color;
    }

    bool operator!=(const Vehiculo& v) const {
        return this->color != v.color;
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
#endif