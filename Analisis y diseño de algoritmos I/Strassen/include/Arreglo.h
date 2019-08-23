#ifndef ARREGLO_H
#define ARREGLO_H
//CLASE ARREGLO

template <typename T> class Arreglo
{
    public:
        Arreglo(unsigned int capacidad);    //CONSTRUCTOR
        void agregarPosicion(unsigned int posicion, const T &Elemento); //MODIFICADORA
        unsigned int darCapacidad() const;  //OBSERVADORA
        unsigned int darCantidad() const;   //OBSERVADORA
        bool esVacio(unsigned int posicion) const; //OBSERVADORA
        const T & pedirElemento(unsigned int posicion) const;   //OBSERVADORA
        virtual ~Arreglo(); //DESTRUCTOR

    protected:

    private:
        struct Arr {
            bool vacio;
            T Elemento;
        };

        Arr * arreglo;

        unsigned int cantidad;
        unsigned int capacidad;
};

#endif // ARREGLO_H
