#include "Grafo.h"

#include "iostream"

using namespace std;

template <typename C>
ostream & operator << (ostream & salida, const Grafo<C> & grafo)
{
	// Recorremos todos los vertices
	list<int> vertices;
	grafo.devolver_vertices(vertices);
	list<int>::iterator v = vertices.begin();
	while (v != vertices.end()) {
		salida << "    " << *v << "\n";
		// Recorremos todos los adyacentes de cada vertice
		list<typename Grafo<C>::Arco> adyacentes;
		grafo.devolver_adyacentes(*v, adyacentes);
		typename list<typename Grafo<C>::Arco>::iterator ady = adyacentes.begin();
		while (ady != adyacentes.end()) {
			salida << "    " << *v << "-> " << ady->devolver_adyacente() << " (" << ady->devolver_costo() << ")\n";
			ady++;
		}
		v++;
	}

	cout << endl;
	cout << "DFS: ";
    list<int> otraLista;
    grafo.devolver_ordenProfundidad(otraLista);
    list<int>::iterator it;
    for (it = otraLista.begin(); it != otraLista.end(); it++)
        cout << (*it) << " ";
    cout << endl;

	return salida;
}

int main(int argc, char **argv)
{
	Grafo<int> g;

	// Cargamos un grafo
	// Primero los vértices
	g.agregar_vertice(1);
	g.agregar_vertice(2);
	g.agregar_vertice(3);
	g.agregar_vertice(4);
	g.agregar_vertice(5);
	g.agregar_vertice(6);
	g.agregar_vertice(7);

	// Luego los arcos
	g.agregar_arco(1, 2, 1);
	g.agregar_arco(1, 3, 1);
	g.agregar_arco(1, 5, 1);
	g.agregar_arco(2, 3, 2);
	g.agregar_arco(2, 5, 2);
	g.agregar_arco(3, 6, 3);
	g.agregar_arco(4, 5, 4);
	g.agregar_arco(5, 6, 5);
	g.agregar_arco(5, 7, 1);

    g.dfs(5);

	cout << "Estructura del grafo h:\n" << g << "\n";

	return 0;
}
