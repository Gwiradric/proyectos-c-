#ifndef CIRCULO_H_INCLUDED
#define CIRCULO_H_INCLUDED

#include "Figura.h"
#include <cmath>

class Circulo : public Figura
{
public:
    Circulo(unsigned int x, unsigned int y, unsigned int radio) : Figura("Circulo") {
        this->x = x;
        this->y = y;
        this->radio = radio;}

    ~Circulo() {};

    double obtenerSuperficie() const {
        return 3.14 * pow((double) radio, 2.0);
    }
private:
    unsigned int x;
    unsigned int y;
    unsigned int radio;
};


#endif // CIRCULO_H_INCLUDED
