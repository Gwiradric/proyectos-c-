#include <iostream>
#include "Lista_Iterador.h"
#include "Lista.h"

using namespace std;

void mostrar_elementos(const Lista<string> & lista) {
    Lista<string>::Const_Iterador it = lista.devolver_iterador();
    while (!it.llego_al_final()) {
        cout << it.elemento_actual() << endl;
        it.avanzar();
    }
}
int main()
{
    Lista_Iterador<string> lista_it;
    lista_it.agregar_principio("Elem1");
    lista_it.agregar_principio("Elem2");
    lista_it.agregar_principio("Elem3");

    cout << "Elementos de la lista, acceso por posición: " << endl;
    for(int posicion = 1; posicion <= lista_it.cantidad_elementos(); posicion++) {
        cout << posicion << ": " << lista_it.obtener_elemento(posicion) << endl;
    }

    cout << endl << "Usando el iterador: " << endl;
    lista_it.iniciar_iterador();
    while (!lista_it.llego_al_final()) {
        cout << lista_it.elemento_actual() << endl;
        lista_it.avanzar_iterador();
    }

    cout << endl << "Lista e iterador separados: " << endl;

    Lista<string> lista;
    lista.agregar_principio("Elem1");
    lista.agregar_principio("Elem2");
    lista.agregar_principio("Elem3");

    Lista<string>::Iterador it = lista.devolver_iterador();
    while (!it.llego_al_final()) {
        cout << it.elemento_actual() << endl;
        it.avanzar();
    }

    cout << endl << "Acceso constante: " << endl;
    mostrar_elementos(lista);
    return 0;
}
