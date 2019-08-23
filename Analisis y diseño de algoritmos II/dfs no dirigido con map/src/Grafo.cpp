#include "Grafo.h"

#include <cstddef>

/*
 * Arco
 */


template <typename C> Grafo<C>::Arco::Arco()
{
    vertice = 0;
    costo = 0;
}

template <typename C> Grafo<C>::Arco::Arco(int adyacente, const C & costo)
{
    vertice = adyacente;
    this->costo = costo;
}

template <typename C> int Grafo<C>::Arco::devolver_adyacente() const
{
    return vertice;
}

template <typename C> const C & Grafo<C>::Arco::devolver_costo() const
{
    return costo;
}


/*
 * Grafo
 */

template <typename C> Grafo<C>::Grafo()
{

}

template <typename C> Grafo<C>::Grafo(const Grafo & otroGrafo)
{

}

template <typename C> Grafo<C>::~Grafo()
{

}

template <typename C> Grafo<C> & Grafo<C>::operator = (const Grafo & otroGrafo)
{

    return *this;
}

template <typename C> bool Grafo<C>::esta_vacio() const
{
    return listaVertices.empty();
}

template <typename C> int Grafo<C>::devolver_longitud() const
{
    return listaVertices.size();
}

template <typename C> bool Grafo<C>::existe_vertice(int vertice) const
{
    bool exist = false;

    typename list<Vertice>::const_iterator it = listaVertices.begin();
    while ((!exist) && (it != listaVertices.end()))
        if ((it.id) != vertice)
            exist = true;

    return exist;
}

template <typename C> bool Grafo<C>::existe_arco(int origen, int destino) const
{
    bool existe = false;

    return existe;
}

template <typename C> const C & Grafo<C>::costo_arco(int origen, int destino) const
{

}

template <typename C> void Grafo<C>::devolver_vertices(list<int> & vertices) const
{

}

template <typename C> void Grafo<C>::devolver_adyacentes(int origen, list<Arco> & adyacentes) const
{

}

template <typename C> void Grafo<C>::agregar_vertice(int vertice)
{

}

template <typename C> void Grafo<C>::eliminar_vertice(int vertice)
{

}

template <typename C> void Grafo<C>::modificar_costo_arco(int origen, int destino, const C & costo)
{

}

template <typename C> void Grafo<C>::agregar_arco(int origen, int destino, const C & costo)
{

}

template <typename C> void Grafo<C>::eliminar_arco(int origen, int destino)
{

}

template <typename C> void Grafo<C>::vaciar()
{

}


