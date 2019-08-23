#include <iostream>

#include "AdministradorFiguras.h"
#include "Circulo.h"
#include "Rectangulo.h"

using namespace std;

int main()
{
    AdministradorFiguras adm;

    adm.agregar(new Circulo(0,0,5));
    adm.agregar(new Circulo(2,2,3));
    adm.agregar(new Rectangulo(0,0,3,4));

    adm.procesar();

    return 0;
}
