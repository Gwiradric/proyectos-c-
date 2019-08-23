#ifndef GRAFO_H_
#define GRAFO_H_

#include <list>
#include <map>
#include <iostream>
#include <cassert>

using namespace std;

template <typename C> class Grafo
{
public:
	class Arco
	{
	public:
		Arco();
		Arco(int adyacente, const C & costo);
		int devolver_adyacente() const;
		const C & devolver_costo() const;
		void modificar_costo(const C & costo);
	private:
		int vertice;
		C costo;
	}; // class Arco

public:
	// NOTA: Dependiendo de la implementación puede ser necesario incluir otras funciones constructuras
	Grafo();
	Grafo(const Grafo & otroGrafo);

	~Grafo();

	Grafo & operator = (const Grafo & otroGrafo);

	// Devuelve true si la cantidad de vértices es cero
	bool esta_vacio() const;

	// Indica la cantidad de vértices del grafo
	int devolver_longitud() const;

	bool existe_vertice(int vertice) const;

	bool existe_arco(int origen, int destino) const;

	// PRE CONDICION: existe_arco(origen, destino)
	const C & costo_arco(int origen, int destino) const;

	void devolver_vertices(list<int> & vertices) const;

	void devolver_adyacentes(int origen, list<Arco> & adyacentes) const;

	void agregar_vertice(int vertice);

	// POST CONDICION: Para todo vértice v != vertice: !existeArco(v, vertice) && !existeArco(vertice, v)
	void eliminar_vertice(int vertice);

	// PRE CONDICION: existeArco(origen, destino)
	void modificar_costo_arco(int origen, int destino, const C & costo);

	// PRE CONDICION: existeVertice(origen) && existeVertice(destino)
	// POST CONDICION: existeArco(origen, destino)
	void agregar_arco(int origen, int destino, const C & costo);

	// POST CONDICION: !existeArco(origen, destino)
	void eliminar_arco(int origen, int destino);

	void vaciar();

private:

	struct Vertice {
        int id;
        list<Arco> listaAdyacentes;
    };

	list<Vertice> listaVertices;

}; // class Grafo

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

template <typename C> void Grafo<C>::Arco::modificar_costo(const C & costo)
{
    this->costo = costo;
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
    return (listaVertices.size() == 0);
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
    {
        if (it->id == vertice)
            exist = true;
        it++;
    }

    return exist;
}

template <typename C> bool Grafo<C>::existe_arco(int origen, int destino) const
{
    bool existe = false;

    if (existe_vertice(origen) && existe_vertice(destino))
    {
        typename list<Vertice>::const_iterator it = listaVertices.begin();

        while ((it->id != origen) && (it != listaVertices.end()))
            it++;

        typename list<Arco>::const_iterator it2 = it->listaAdyacentes.begin();

        if (it->id == origen)
            while ((!existe) && (it2 != it->listaAdyacentes.end()))
            {
                if (it2->devolver_adyacente() == destino)
                    existe = true;
                it2++;
            }
    }
    return existe;
}

template <typename C> const C & Grafo<C>::costo_arco(int origen, int destino) const
{
    assert(existe_arco(origen, destino));
    typename list<Vertice>::const_iterator it = listaVertices.begin();

    while (it->id != origen)
        it++;

    typename list<Arco>::const_iterator it2 = it->listaAdyacentes.begin();

    while (it2->devolver_adyacente() != destino)
        it2++;

    return it2->devolver_costo();
}

template <typename C> void Grafo<C>::devolver_vertices(list<int> & vertices) const
{
    typename list<Vertice>::const_iterator it = listaVertices.begin();

    while (it != listaVertices.end())
    {
        vertices.push_back(it->id);
        it++;
    }
}

template <typename C> void Grafo<C>::devolver_adyacentes(int origen, list<Arco> & adyacentes) const
{
    typename list<Vertice>::const_iterator it = listaVertices.begin();
    typename list<Arco>::const_iterator it2;

    while ((it->id != origen) && (it != listaVertices.end()))
        it++;

    if (it->id == origen)

    it2 = it->listaAdyacentes.begin();

    while (it2 != it->listaAdyacentes.end())
    {
        Arco aux(it2->devolver_adyacente(), it2->devolver_costo());
        adyacentes.push_back(aux);
        it2++;
    }
}

template <typename C> void Grafo<C>::agregar_vertice(int vertice)
{
    if (!existe_vertice(vertice))
    {
        Vertice aux;

        aux.id = vertice;

        listaVertices.push_back(aux);
    }
}

template <typename C> void Grafo<C>::eliminar_vertice(int vertice)
{
    typename list<Vertice>::iterator it = listaVertices.begin();
    typename list<Arco>::iterator it2;

    while (it != listaVertices.end())
    {
        if (it->id == vertice)
            it = listaVertices.erase(it);
        else
            {
                it2 = it->listaAdyacentes.begin();
                while (it2 != it->listaAdyacentes.end() && (it2->devolver_adyacente() != vertice))
                    it2++;
                if (it2->devolver_adyacente() == vertice)
                    it2 = it->listaAdyacentes.erase(it2);
            }

    it++;
    }
}

template <typename C> void Grafo<C>::modificar_costo_arco(int origen, int destino, const C & costo)
{
    if (existe_arco(origen, destino))
    {
        typename list<Vertice>::iterator it = listaVertices.begin();
        typename list<Arco>::iterator it2;

        while ((it->id != origen) && (it != listaVertices.end()))
            it++;

        if (it->id == origen)
            it2 = it->listaAdyacentes.begin();

        while (it2->devolver_adyacente() != destino)
            it2++;

        if (it2->devolver_adyacente() == destino)
            it2->modificar_costo(costo);
    }
}

template <typename C> void Grafo<C>::agregar_arco(int origen, int destino, const C & costo)
{
    if ((existe_vertice(origen)) && (existe_vertice(destino)))
    {
        typename list<Vertice>::iterator it = listaVertices.begin();

        while ((it->id != origen) && (it != listaVertices.end()))
            it++;

        if (it->id == origen)
        {
            Arco g(destino,costo);
            it->listaAdyacentes.push_back(g);
        }
    }
}

template <typename C> void Grafo<C>::eliminar_arco(int origen, int destino)
{
    typename list<Vertice>::iterator it = listaVertices.begin();
    typename list<Arco>::iterator it2;

    while ((it->id != origen) && (it != listaVertices.end()))
        it++;

    if (it->id == origen)
    {
        it2 = it->listaAdyacentes.begin();
        while (it2->devolver_adyacente() != destino)
            it2++;

        it2 = it->listaAdyacentes.erase(it2);
    }
}

template <typename C> void Grafo<C>::vaciar()
{

}

#endif /* GRAFO_H_ */

