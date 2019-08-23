#include "Coleccion_Inmuebles.h"


Coleccion_Inmuebles::Coleccion_Inmuebles()
{
}

Coleccion_Inmuebles::~Coleccion_Inmuebles()
{
}

void Coleccion_Inmuebles::agregar(const Inmueble & inmueble)
{
    mapa.insert(make_pair<string, Inmueble>(inmueble.obtener_identificador(), (Inmueble) inmueble));

    mapa[inmueble.obtener_identificador()] = inmueble;

    lista.push_back(inmueble);
}

bool Coleccion_Inmuebles::eliminar(string id)
{
    return false;
}

bool Coleccion_Inmuebles::existe_barrio(string barrio) const
{
    return false;
}

void Coleccion_Inmuebles::filtrar_por_precio(float precio, Coleccion_Inmuebles & resultado) const
{

}

bool Coleccion_Inmuebles::existe(string id) const
{
   map<string, Inmueble>::const_iterator it = mapa.find(id);
   if (it != mapa.end())
       return true;

    //Si la estructura sería una lista.
   list<Inmueble>::const_iterator itLista = lista.begin();
   while (itLista != lista.end()) {
        if (itLista->obtener_identificador() == id)
            return true;
        itLista++;
   }
   return false;
}
