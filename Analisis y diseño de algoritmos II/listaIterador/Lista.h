#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

template <typename Elem>
class Lista
{
private:
    class Nodo {
    public:
        Nodo(const Elem & elem, Nodo * sig);
        Elem elemento;
        Nodo * siguiente;
    }; //class Nodo

public:
    class Iterador {
        friend class Lista;
    public:
        Elem & elemento_actual();
        void avanzar();
        bool llego_al_final() const;
    private:
        Iterador(Nodo * inicio) { it = inicio; }
        Nodo * it;
    }; // class Iterador

    class Const_Iterador {
        friend class Lista;
    public:
        const Elem & elemento_actual() const;
        void avanzar();
        bool llego_al_final() const;
    private:
        Const_Iterador(Nodo * inicio) { it = inicio; }
        Nodo * it;
    };

public:
    Lista();
    ~Lista();

    void agregar_principio(const Elem & e);
    int cantidad_elementos() const;

    Iterador devolver_iterador() { return Iterador(inicio); }
    Const_Iterador devolver_iterador() const { return Const_Iterador(inicio); }

private:
    Nodo * inicio;
    int cant_elementos;
};

template <typename Elem>
Lista<Elem>::Nodo::Nodo(const Elem & elem, Nodo * sig) {
    this->elemento = elem;
    this->siguiente = sig;
}

template <typename Elem>
Elem & Lista<Elem>::Iterador::elemento_actual() {
    return it->elemento;
}

template <typename Elem>
void Lista<Elem>::Iterador::avanzar(){
    it = it->siguiente;
}

template <typename Elem>
bool Lista<Elem>::Iterador::llego_al_final() const{
    return (it == NULL);
}

template <typename Elem>
const Elem & Lista<Elem>::Const_Iterador::elemento_actual() const {
    return it->elemento;
}

template <typename Elem>
void Lista<Elem>::Const_Iterador::avanzar(){
    it = it->siguiente;
}

template <typename Elem>
bool Lista<Elem>::Const_Iterador::llego_al_final() const{
    return (it == NULL);
}

template <typename Elem>
Lista<Elem>::Lista() {
    inicio = NULL;
    cant_elementos = 0;
}

template <typename Elem>
Lista<Elem>::~Lista() {
    //TODO:
}

template <typename Elem>
void Lista<Elem>::agregar_principio(const Elem & elem) {
    Nodo * aux = new Nodo(elem, inicio);
    inicio = aux;
    cant_elementos++;
}

template <typename Elem>
int Lista<Elem>::cantidad_elementos() const{
    return cant_elementos;
}
#endif // LISTA_H_INCLUDED
