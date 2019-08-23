#include <iostream>

#include "Inmueble.h"
#include "Coleccion_Inmuebles.h"
#include "list"

using namespace std;

int main()
{
    Inmueble inm, inm2;

    inm.cambiar_identificador("140");
    inm.cambiar_precio(1500);
    inm.cambiar_barrio("luz");
    inm.cambiar_descripcion("depto");

    inm2.cambiar_identificador("1");
    inm2.cambiar_precio(2000);
    inm2.cambiar_barrio("casino");
    inm2.cambiar_descripcion("depto");

    Coleccion_Inmuebles coleccion;

    coleccion.agregar(inm);
    coleccion.agregar(inm2);

    cout << coleccion.existe("140") << endl;
    cout << coleccion.existe("200") << endl;
    cout << coleccion.existe("1") << endl;

    return 0;
}
