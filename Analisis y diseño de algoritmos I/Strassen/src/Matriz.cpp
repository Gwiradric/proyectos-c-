#include "Matriz.h"
#include <cstddef>

template <typename T>
Matriz<T>::Matriz(unsigned int tam)
//ESTA FUNCION ES EL CONSTRUCTOR DE LA CLASE MATRIZ
//CREA LA MATRIZ Y LA INICIALIZA EN 0
{
    this->tam = tam;

    matriz = new T * [tam];
    for (unsigned int f = 0; f < tam; f++)
        matriz[f] = new T[tam];

    for (unsigned int f=0; f<tam; f++)
        for (unsigned int c=0; c<tam; c++)
            matriz[f][c]=0;
}

template <typename T>
unsigned int Matriz<T>::obtenerTam() const
//ESTA FUNCION DEVUELVE EL TAMAÑO DE LA MATRIZ
{
    return tam;
}

template <typename T>
void Matriz<T>::agregarElemento(const T &Elemento, unsigned int alto, unsigned int ancho)
//ESTA FUNCION PERMITE ALMACENAR UN ELEMENTO EN LA MATRIZ EN LA POSICION DADA
{
    matriz[alto][ancho] = Elemento;
}

template <typename T>
const T & Matriz<T>::obtenerElemento(unsigned int alto, unsigned int ancho) const
//ESTA FUNCION DEVUELVE EL ELEMENTO DE LA MATRIZ EN LA POSICION DADA
{
    return matriz[alto][ancho];
}

template <typename T>
void Matriz<T>::sumaMatriz(const Matriz<T> & A, const Matriz<T> & B)
//ESTA FUNCION SE ENCARGA DE REALIZAR LA SUMA ENTRE DOS MATRICES Y GUARDAR LOS RESULTADOS EN ESTA MATRIZ
 {
    for (unsigned int f = 0; f < tam; f++)
        for (unsigned int c = 0; c < tam; c++)
            matriz[f][c] = A.obtenerElemento(f,c) + B.obtenerElemento(f,c);

}

template <typename T>
void Matriz<T>::restaMatriz(const Matriz<T> & A, const Matriz<T> & B)
//ESTA FUNCION SE ENCARGA DE REALIZAR LA RESTA ENTRE DOS MATRICES Y GUARDAR LOS RESULTADOS EN ESTA MATRIZ
{
 for (unsigned int f = 0; f < tam; f++)
        for (unsigned int c = 0; c < tam; c++)
            matriz[f][c] = A.obtenerElemento(f,c) - B.obtenerElemento(f,c);
}

template <typename T>
void Matriz<T>::prodMatriz(const Matriz<T> & A, const Matriz<T> & B)
//FUNCIÓN PARA MULTIPLICAR MATRICES DE 1x1 DENTRO DE ALGORITMO DE STRASSEN
{
    for (unsigned int f=0;f<tam;f++)
        {
        for (unsigned int c=0; c<tam; c++)
            {
            matriz[f][c]=0;
            for (unsigned int k=0;k<tam;k++)
                matriz[f][c]= matriz[f][c] + A.obtenerElemento(f,k) * B.obtenerElemento(k,c);
           }
        }
}

template <typename T>
void Matriz<T>::crearCuadrante(const Matriz<T> & A, unsigned int f, unsigned int c, unsigned int f1, unsigned int c1)
//ESTA FUNCION SE ENCARGA DE CREAR UN CUADRANTE CON LAS POSICIONES DADAS
{
    matriz[f][c] = A.obtenerElemento(f1,c1);
}

template <typename T>
Matriz<T>::~Matriz()
//DESTRUCTOR DE LA CLASE. NO SE IMPLIMENTA POR LOS PROBLEMAS YA MENCIONADOS EN CLASE
//DE LA PÉRDIDA DEL PUNTERO EN UNA COPIA DE UNA MATRIZ Y LA DESTRUCCIÓN DE LA MISMA.
{
    if(matriz != NULL)
        {
        for (unsigned int f=0; f<tam; f++)
            delete [] matriz[f];
        delete [] matriz;
        matriz = NULL;
        }
}

template class Matriz<int>;
template class Matriz<float>;
template class Matriz<unsigned int>;
