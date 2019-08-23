#ifndef RECTANGULO_H_INCLUDED
#define RECTANGULO_H_INCLUDED

#include "Figura.h"

class Rectangulo : public Figura
{
public:
    Rectangulo(unsigned int x, unsigned int y, unsigned int base, unsigned int altura) : Figura("Rectangulo") {
        this->x = x;
        this->y = y;
        this->base = base;
        this->altura = altura;}

    ~Rectangulo() {}

    double obtenerSuperficie() const {
        return base * altura;}
private:
    unsigned int x;
    unsigned int y;
    unsigned int base;
    unsigned int altura;
};

#endif // RECTANGULO_H_INCLUDED
