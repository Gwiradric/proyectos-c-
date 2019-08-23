#ifndef MATRIZ_H
#define MATRIZ_H

template <typename T>
class Matriz
{
    public:
        Matriz(unsigned int tam); //CONSTRUCTOR DE LA CLASE
        void agregarElemento(const T &Elemento, unsigned int Alto, unsigned int Ancho); //MODIFICADORA
        unsigned int obtenerTam() const;    //OBSERVADORA
        const T & obtenerElemento(unsigned int alto, unsigned int ancho) const; //OBSERVADORA
        void sumaMatriz(const Matriz<T> & A, const Matriz<T> & B);  //MODIFICADORA
        void restaMatriz(const Matriz<T> & A, const Matriz<T> & B); //MODIFICADORA
        void prodMatriz(const Matriz<T> & A, const Matriz<T> & B);  //MODIFICADORA
        void crearCuadrante(const Matriz<T> & A, unsigned int f, unsigned int c, unsigned int f1, unsigned int c1); //MODIFICADORA

        virtual ~Matriz();  //DESTRUCTOR

    protected:

    private:

        T ** matriz;

        unsigned int tam;
};

#endif // MATRIZ_H
