#ifndef LISTA_H
#define LISTA_H
//CLASE LISTA

template <typename T> class Lista
{
    public:
        Lista(); //CONSTRUCTOR
        void agregarPrimero(const T &Elemento); //MODIFICADOR
        void agregarUltimo(const T &Elemento);  //MODIFICADOR
        void agregarPosicion(unsigned int posicion, const T &Elemento); //MODIFICADOR
        int darCantidad() const; //CONSTANTE
        bool pertenece(const T &Elemento);  //CONSTANTE
        bool esVacia() const;   //CONSTANTE
        void eliminarElemento(unsigned int posicion);   //MODIFICADORA
        void eliminarTodo(); //MODIFICADORA

        void reset();   //MODIFICADORA
        bool esVaciaAux() const;    //OBSERVADORA
        void siguiente();   //MODIFICADORA
        const T &elemento() const;  //OBSERVADORA
        virtual ~Lista(); //DESTRUCTOR

    protected:

    private:
        struct Nodo {
            T Elemento;
            Nodo * siguiente;
        };

        Nodo * aux;
        Nodo * primero;
        Nodo * ultimo;

        unsigned int cantidad;

        void nuevoNodo(Nodo * &nodo, const T &Elemento);    //MODIFICADORA
        void buscarPosicion(Nodo * &nodo, unsigned int posicion);   //OBSERVADORA
        void pertenece(Nodo * &nodo, bool &esta, const T &Elemento);    //OBSERVADORA
        void eliminarPrimero(); //MODIFICADORA
        void eliminarUltimo();  //MODIFICADORA
};

#endif // LISTA_H
