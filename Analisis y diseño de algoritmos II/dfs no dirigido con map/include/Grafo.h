#ifndef GRAFO_H_
#define GRAFO_H_

#include <iostream>
#include <map>
#include <list>
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
	Grafo();
	Grafo(const Grafo & otroGrafo);

	~Grafo();

	Grafo & operator = (const Grafo & otroGrafo);

	bool esta_vacio() const;
	int devolver_longitud() const;
    bool existe_vertice(int vertice) const;
    bool existe_arco(int origen, int destino) const;
	const C & costo_arco(int origen, int destino) const;
	void devolver_vertices(list<int> & vertices) const;
	void devolver_adyacentes(int origen, list<Arco> & adyacentes) const;

	void agregar_vertice(int vertice);
	void eliminar_vertice(int vertice);
	void modificar_costo_arco(int origen, int destino, const C & costo);
	void agregar_arco(int origen, int destino, const C & costo);
	void eliminar_arco(int origen, int destino);
	void vaciar();

	void dfs(int vertice);
	void dfsutils(int vertice, bool visitado[]);
	void devolver_ordenProfundidad(list<int> & otraLista) const;

private:

	map<int, map<int, C> > vertices;
	list<int> ordenProfundidad;

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
    vertices = otroGrafo.vertices;
}

template <typename C> Grafo<C>::~Grafo()
{

}

template <typename C> Grafo<C> & Grafo<C>::operator = (const Grafo & otroGrafo)
{


    return *this->vertices;
}

template <typename C> bool Grafo<C>::esta_vacio() const
{
    return (vertices.size() == 0);
}

template <typename C> int Grafo<C>::devolver_longitud() const
{
    return vertices.size();
}

template <typename C> bool Grafo<C>::existe_vertice(int vertice) const
{
    bool exist = false;

    typename map<int, map<int, C> >::const_iterator it = vertices.find(vertice);
    if (it->first == vertice)
        exist = true;

    return exist;
}

template <typename C> bool Grafo<C>::existe_arco(int origen, int destino) const
{
    bool exist = false;

    typename map<int, map<int, C> >::const_iterator it = vertices.find(origen);
    typename map<int, C>::const_iterator it2 = it->second.find(destino);

    if (it2 != it->second.end())
        exist = true;

    return exist;
}

template <typename C> const C & Grafo<C>::costo_arco(int origen, int destino) const
{
    assert(existe_vertice(origen) && existe_arco(origen, destino));

    typename map<int, map<int, C> >::const_iterator it = vertices.find(origen);
    typename map<int, C>::const_iterator it2 = it->second.find(destino);

    return it2->second;
}

template <typename C> void Grafo<C>::devolver_vertices(list<int> & vertices) const
{
    if (devolver_longitud() > 0)
    {
        typename map<int, map<int, C> >::const_iterator it;

        for (it = this->vertices.begin(); it != this->vertices.end(); it++)
            vertices.push_back(it->first);
    }
}

template <typename C> void Grafo<C>::devolver_adyacentes(int origen, list<Arco> & adyacentes) const
{
    if (devolver_longitud() > 0)
    {

        typename map<int, map<int, C> >::const_iterator it = vertices.find(origen);
        typename map<int, C>::const_iterator it2;

        for (it2 = it->second.begin(); it2 != it->second.end(); it2++)
        {
            Arco aux(it2->first, it2->second);
            adyacentes.push_back(aux);
        }
    }
}



template <typename C> void Grafo<C>::agregar_vertice(int vertice)
{
    if (!existe_vertice(vertice))
    {
        // Agrego el vertice en el mapa
        map<int, C> adyacentes;
        vertices[vertice] = adyacentes;
    }
}

template <typename C> void Grafo<C>::eliminar_vertice(int vertice)
{
    //Pregunto si existe el vertice
    if (existe_vertice(vertice))
    {
        //Defino los iteradores
        typename map<int, map<int, C> >::iterator itV = vertices.find(vertice);
        typename map<int, C>::iterator itA;

        itV->second.clear();
        vertices.erase(itV);

        for (itV = vertices.begin(); itV != vertices.end(); itV++)
            {
                itA = itV->second.find(vertice);
                if (itA != itV->second.end())
                    itV->second.erase(itA);
            }
    }
}

template <typename C> void Grafo<C>::modificar_costo_arco(int origen, int destino, const C & costo)
{
    if ((existe_vertice(origen)) && (existe_arco(origen, destino)))
        {
            typename map<int, map<int, C> >::iterator it = vertices.find(origen);

            it->second[destino] = costo;
        }
}

template <typename C> void Grafo<C>::agregar_arco(int origen, int destino, const C & costo)
{
    if ((existe_vertice(origen)) && (existe_vertice(destino)))
    {
        //Agrego el arco entre el origen y el destino
        typename map<int, map<int, C> >::iterator it = vertices.find(origen);
        it->second[destino] = costo;

        //Agrego el arco entre el destino y el origen
        it = vertices.find(destino);
        it->second[origen] = costo;
    }
}

template <typename C> void Grafo<C>::eliminar_arco(int origen, int destino)
{
    typename map<int, map<int, C> >::iterator it = vertices.find(origen);
    typename map<int, C>::iterator it2 = it->second.find(destino);

    it->second.erase(it2);
}

template <typename C> void Grafo<C>::vaciar()
{
    if (!esta_vacio())
    {
        typename map<int, map<int, C> >::iterator itV;
        for (itV = vertices.begin(); itV != vertices.end(); itV++)
            itV->second.clear();
        vertices.clear();
    }
}

template <typename C> void Grafo<C>::dfs(int vertice)
{
    // Marcar todo el arreglo como no visitado
    bool *visitado = new bool[devolver_longitud()];
    for (int i = 0; i < devolver_longitud(); i++)
        visitado[i] = false;

    // Llamar recursivamente a la funcion
    dfsutils(vertice, visitado);
}

template <typename C> void Grafo<C>::dfsutils(int vertice, bool visitado[])
{
    visitado[vertice] = true;
    ordenProfundidad.push_back(vertice);

    typename map<int, map<int, C> >::iterator itV = vertices.find(vertice);
    typename map<int, C>::iterator itA;

    for (itA = itV->second.begin(); itA != itV->second.end(); ++itA)
        if (!visitado[itA->first])
            dfsutils(itA->first, visitado);
}

template <typename C> void Grafo<C>::devolver_ordenProfundidad(list<int> &otraLista) const
{
    list<int>::const_iterator it;
    for (it = ordenProfundidad.begin(); it != ordenProfundidad.end(); it++)
        otraLista.push_back((*it));
}

#endif /* GRAFO_H_ */

