#include "Arreglo.h"
#include <assert.h>

template <typename T>
Arreglo<T>::Arreglo(unsigned int capacidad)
//CONSTRUCTOR DEL ARREGLO
{
    arreglo = new Arr[capacidad];
    cantidad = 0;
    this->capacidad = capacidad;
    for (unsigned int i=0;i<capacidad;i++)
        arreglo[i].vacio = true;
}

template <typename T>
void Arreglo<T>::agregarPosicion(unsigned int posicion, const T &Elemento)
//AGREGA UN NUEVO ELEMENTO CREANDO UN NUEVO ARREGLO
{
    if (posicion < capacidad)
    {
        arreglo[posicion].Elemento = Elemento;
        arreglo[posicion].vacio=false;
        cantidad++;
    }
}

template <typename T>
unsigned int Arreglo<T>::darCantidad() const
//ESTA FUNCION DEVUELVE LA CAPACIDAD DEL ARREGLO
{
    return cantidad;
}

template <typename T>
unsigned int Arreglo<T>::darCapacidad() const
//ESTA FUNCION DEVUELVE LA CAPACIDAD DEL ARREGLO
{
    return capacidad;
}

template <typename T>
bool Arreglo<T>::esVacio(unsigned int posicion) const
{
    return arreglo[posicion].vacio;
}

template <typename T>
const T & Arreglo<T>::pedirElemento(unsigned int posicion) const
//ESTA FUNCION DEVUELVE EL ELEMENTO DEL ARREGLO EN LA POSICION DADA
{
    assert(posicion < capacidad);
    assert(!arreglo[posicion].vacio);
    return arreglo[posicion].Elemento;
}

template <typename T>
Arreglo<T>::~Arreglo()
//DESTRUCTOR DEL ARREGLO
{
    delete [] arreglo;
    cantidad = 0;
    capacidad = 0;
}

//ACEPTA CLASES DE INT Y CHAR
template class Arreglo<int>;
template class Arreglo<char>;
