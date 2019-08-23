#include "Lista.h"
#include <cstddef>

template <typename T> Lista<T>::Lista()
//VARIABLES DE LA CLASE INICIALIZADAS EN 0 NULL
{
    primero = NULL;
    ultimo = NULL;
    aux = primero;
    cantidad = 0;
}

template <typename T> void Lista<T>::nuevoNodo(Nodo * &nodo, const T &Elemento)
//ESTA FUNCION INICIALIZA UN NODO EN NULL CON EL ELEMENTO Y EL PUNTERO SIGUIENTE EN NULL
{
    nodo = new Nodo;
    nodo->Elemento = Elemento;
    nodo->siguiente = NULL;
}

template <typename T> void Lista<T>::agregarPrimero(const T &Elemento)
//ESTA FUNCION AGREGA UN NODO EN EL INICIO DE LA LISTA
{
    Nodo * nodo = NULL;
    nuevoNodo(nodo, Elemento);
    if (cantidad == 0) //SI LA LISTA TIENE 0 ELEMENTOS EL NODO ES EL PRIMERO Y ULTIMO
    {
        primero = nodo;
        ultimo = nodo;
        aux = primero;
    } else
    {
        nodo->siguiente = primero;
        primero = nodo;
        aux = primero;
    }
    cantidad++;
}

 template <typename T> void Lista<T>::agregarUltimo(const T &Elemento)
 //ESTA FUNCION AGREGA UN NODO AL FINAL DE LA LISTA
{
    Nodo * nodo = NULL;
    nuevoNodo(nodo, Elemento);
    if (cantidad == 0)
        agregarPrimero(Elemento); //SI SE LLAMA A ESTA FUNCION CON CANTIDAD 0 SE LLAMA A AGREGAR PRIMERO
    else
    {
        ultimo->siguiente = nodo;
        ultimo = nodo;
    }
    cantidad++;
}

template <typename T> void Lista<T>::buscarPosicion(Nodo * &nodo, unsigned int posicion)
//ESTA FUNCION BUSCA UN NODO EN LA LISTA, MODIFICANDO EL PUNTERO QUE SE PASA POR REFERENCIA
{
    unsigned int contador = 1;
    while (contador < posicion)
    {
        nodo = nodo->siguiente;
        contador++;
    }
}

template <typename T> void Lista<T>::agregarPosicion(unsigned int posicion, const T &Elemento)
//ESTA FUNCION ES PARA INSERTAR EL NODO EN UNA POSICION ESPECIFICA, COMO YA SE DEFINIO AGREGAR PRIMERO
//Y AGREGAR ULTIMO SE LOS VUELVE A LLAMAR PARA ELIMINAR ESOS POSIBLES CASOS
{
    if (posicion == 0)
        agregarPrimero(Elemento);
    else
        if (posicion == cantidad+1)
            agregarUltimo(Elemento);
        else
            if (posicion < cantidad)
                //LA POSICION DEBE ESTAR DENTRO DEL RANGO 0 HASTA CANTIDAD-1 PORQUE
                //CANTIDAD 1 EQUIVALE A POSICION 0
            {
                Nodo * nodo = NULL;
                nuevoNodo(nodo, Elemento);
                Nodo * nodo2 = primero;
                buscarPosicion(nodo2, posicion);
                nodo->siguiente = nodo2->siguiente;
                nodo2->siguiente = nodo;
                cantidad++;
            }
}

template <typename T> int Lista<T>::darCantidad() const
//FUNCION QUE DEVUELVE LA CANTIDAD DE ELEMENTOS EN LA LISTA
{
    return cantidad;
}

template <typename T> void Lista<T>::pertenece(Nodo * &nodo, bool &esta, const T &Elemento)
//ESTA FUNCION MODIFICA EL BOOLEANO PASADO POR REFERENCIA, DONDE USANDO RECURSION BUSCA EL ELEMENTO EN LA LISTA
{
    while ((nodo != NULL) && (nodo->Elemento != Elemento))
        nodo=nodo->siguiente;
    if (nodo != NULL)
        esta=true;
}

template <typename T> bool Lista<T>::pertenece(const T &Elemento)
//ESTA FUNCION ES LA ENCARGADA DE LLAMARSE A SI MISMA PARA PODER DEVOLVER EL BOLEANO PERTENECE
//EN EL MENU PRINCIPAL
{
    bool esta = false;
    Nodo * nodo = primero;
    pertenece(nodo, esta, Elemento);
    nodo = NULL;
    return esta;
}

template <typename T> bool Lista<T>::esVacia() const
//ESTA FUNCION DEVUELVE UN BOOLEANO DEPENDIENDO DE SI LA LISTA POSEE ELEMENTOS O NO
{
    return (primero == NULL);
}

template <typename T> void Lista<T>::eliminarUltimo()
//ESTA FUNCION ELIMINA EL ULTIMO NODO DE LA LISTA Y ACTUALIZA A ULTIMO A SU ANTERIOR
{
    if (ultimo != NULL)
    {
        Nodo * aux = ultimo;
        Nodo * aux2 = primero;
        buscarPosicion(aux2, cantidad-1);
        aux2->siguiente=NULL;
        ultimo= aux2;
        delete aux;
        cantidad--;
    }
}

template <typename T> void Lista<T>::eliminarElemento(unsigned int posicion)
//SE BUSCA UN ELEMENTO POR LA POSICION Y SE ELIMINA, DISMINUYENDO LA CANTIDAD
{
    if (posicion <= cantidad)
    {
        if (posicion == 1)
            eliminarPrimero();
                else
                    if (posicion == cantidad)
                        eliminarUltimo();
                    else
                   {
                       Nodo * nodo = primero;
                       buscarPosicion(nodo, posicion-1);
                       Nodo * nodo2 = nodo->siguiente;
                       nodo->siguiente = nodo2->siguiente;
                       nodo2->siguiente = NULL;
                       delete nodo2;
                       cantidad--;
                   }
    }
}

template <typename T> void Lista<T>::eliminarPrimero()
//ELIMINA EL PRIMER NODO DE LA LISTA
{
    if (primero != NULL)
    {
        Nodo * nodo = primero;
        primero = nodo->siguiente;
        cantidad--;
        aux = primero;
        delete nodo;
    }
}

template <typename T> void Lista<T>::eliminarTodo()
//ELIMINA TODA LA LISTA DESDE EL PRIMER NODO HASTA EL ULTIMO USANDO LA FUNCION DE ELIMINAR PRIMERO
{
    while (cantidad != 0)
        eliminarPrimero();
    primero=NULL;
    ultimo=NULL;
    aux=NULL;
}

template <typename T> void Lista<T>::reset()
//AUX SE VUELVE PRIMERO
//SE NECESITA PARA ITERAR
{
    aux = primero;
}

template <typename T> bool Lista<T>::esVaciaAux() const
//ESTA FUNCION DEVUELVE UN BOLEANO CUYO RESULTADO VA A DEPENDER DE SI AUX ES VACIO O NO,
//SE NECESITA PARA PODER ITERAR
{
    return (aux == NULL);
}

template <typename T> void Lista<T>::siguiente()
//CON ESTA FUNCION AUX SE VUELVE SU SIGUIENTE, SE NECESITA PARA ITERAR
{
    aux=aux->siguiente;
}

template <typename T> const T & Lista<T>::elemento() const
//ESTA FUNCION DEVUELVE EL ELEMENTO CONTENIDO EN EL NODO AUX, SE NECESITA PARA ITERAR
{
    return aux->Elemento;
}

template <typename T> Lista<T>::~Lista()
//DESTRUCTOR DE LA CLASE
{
    if (cantidad != 0)
       eliminarTodo();
}

//LA LISTA ACEPTA CARACTERES Y ENTEROS
template class Lista<char>;
template class Lista<int>;
