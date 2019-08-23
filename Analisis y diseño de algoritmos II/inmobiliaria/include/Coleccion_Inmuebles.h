#ifndef COLECCIONINMUEBLES_H
#define COLECCIONINMUEBLES_H

#include "Inmueble.h"

#include <map>
#include <list>

using namespace std;

class Coleccion_Inmuebles
{
    public:
        Coleccion_Inmuebles();

        virtual ~Coleccion_Inmuebles();

        bool existe(string id) const;

        void filtrar_por_precio(float precio, Coleccion_Inmuebles & resultado) const;

        bool existe_barrio(string barrio) const;

        void agregar(const Inmueble & nuevo);

        bool eliminar(string id);

    private:
        //Estructura de implementación
        map<string, Inmueble> mapa;

        list<Inmueble> lista;
};

#endif // COLECCIONINMUEBLES_H
