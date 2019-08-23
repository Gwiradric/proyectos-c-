#ifndef ADMINISTRADORFIGURAS_H_INCLUDED
#define ADMINISTRADORFIGURAS_H_INCLUDED

#include <iostream>
#include "list"
#include "Figura.h"

class AdministradorFiguras
{
public:
    AdministradorFiguras() {};
    virtual ~AdministradorFiguras() {};

    virtual unsigned int agregar(Figura * figura) {figuras.push_back(figura); return indiceClave++;};
    virtual void eliminar(unsigned int clave) {}
    virtual Figura * obtener(unsigned int clave) const {return 0;}

    virtual void procesar() const {
        std::list<Figura *>::const_iterator it = figuras.begin();
        while (it != figuras.end()) {
            std::cout << "Area figura " << (*it)->obtenerTipo() << " " <<(*it)->obtenerSuperficie() << std::endl;
            it++;
        }
    };

private:
    unsigned int indiceClave;
    std::list<Figura *> figuras;
};


#endif // ADMINISTRADORFIGURAS_H_INCLUDED
