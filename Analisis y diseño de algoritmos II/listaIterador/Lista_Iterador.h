#ifndef LISTAITERADOR_H_INCLUDED
#define LISTAITERADOR_H_INCLUDED

#include <iostream>
#include <cassert>

template <typename Elem>
class Lista_Iterador
{
private:
    class Nodo {
    public:
        Nodo(const Elem & elem, Nodo * sig);
        Elem elemento;
        Nodo * siguiente;
    }; //class Nodo

public:
    Lista_Iterador();
    ~Lista_Iterador();
    void agregar_principio(const Elem & e);
    void agregar_final(const Elem & e);

    int cantidad_elementos() const;
    const Elem & obtener_elemento(int posicion) const;

    void iniciar_iterador();
    Elem & elemento_actual();
    const Elem & elemento_actual() const;
    void avanzar_iterador();
    bool llego_al_final() const;

private:
    Nodo * inicio, * it;
    int cant_elementos;
};

template <typename Elem>
Lista_Iterador<Elem>::Nodo::Nodo(const Elem & elem, Nodo * sig) {
    this->elemento = elem;
    this->siguiente = sig;
}

template <typename Elem>
Lista_Iterador<Elem>::Lista_Iterador() {
    inicio = NULL;
    it = NULL;
    cant_elementos = 0;
}

template <typename Elem>
Lista_Iterador<Elem>::~Lista_Iterador() {
    //TODO:
}

template <typename Elem>
void Lista_Iterador<Elem>::agregar_principio(const Elem & elem) {
    Nodo * aux = new Nodo(elem, inicio);
    inicio = aux;
    cant_elementos++;
}

template <typename Elem>
void Lista_Iterador<Elem>::agregar_final(const Elem & elem) {
    //TODO:
}

template <typename Elem>
int Lista_Iterador<Elem>::cantidad_elementos() const{
    return cant_elementos;
}

template <typename Elem>
const Elem & Lista_Iterador<Elem>::obtener_elemento(int posicion) const {
    assert((posicion > 0) && (posicion <= cant_elementos));

    Nodo * aux = inicio;
    int actual = 1;
    while (actual < posicion) {
        actual++;
        aux = aux->siguiente;
    }

    return aux->elemento;
}

template <typename Elem>
void Lista_Iterador<Elem>::iniciar_iterador() {
    it = inicio;
}

template <typename Elem>
Elem & Lista_Iterador<Elem>::elemento_actual() {
    assert(it != NULL);
    return it->elemento;
}

template <typename Elem>
const Elem & Lista_Iterador<Elem>::elemento_actual() const {
    assert(it != NULL);
    return it->elemento;
}

template <typename Elem>
void Lista_Iterador<Elem>::avanzar_iterador() {
    assert(it != NULL);
    it = it->siguiente;
}

template <typename Elem>
bool Lista_Iterador<Elem>::llego_al_final() const {
    return (it == NULL);
}


#endif // LISTAITERADOR_H_INCLUDED
