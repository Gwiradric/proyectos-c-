#ifndef FIGURA_H_INCLUDED
#define FIGURA_H_INCLUDED

#include <iostream>

class Figura
{
public:
    Figura(std::string tipo) {this->tipo = tipo;}
    virtual ~Figura() {}

    std::string obtenerTipo() const {return tipo;}
    virtual double obtenerSuperficie() const = 0;
private:
    std::string tipo;
};


#endif // FIGURA_H_INCLUDED
