#include <iostream>
#include <cstddef>
#include <cmath>
#include "Matriz.h"

using namespace std;

void cargarMatriz(Matriz<unsigned int> &A)
//ESTA FUNCION SE ENCARGA DE CARGAR LA MATRIZ INGRESADA POR PARAMETRO DE MANERA GENERICA
{
    for (unsigned int f=0; f < A.obtenerTam(); f++)
        for (unsigned int c=0; c < A.obtenerTam(); c++)
            A.agregarElemento(f * A.obtenerTam() + c + 1,f,c);
}

void imprimirMatriz(Matriz<unsigned int> &A)
//ESTA FUNCION SE ENCARGA DE IMPRIMIR LA MATRIZ INGRESADA POR PARAMETRO
{
    for (unsigned int f=0;f<A.obtenerTam();f++)
    {
        for (unsigned int c=0;c<A.obtenerTam();c++)
            cout << A.obtenerElemento(f,c) << " ";
        cout << endl;
    }
}

void strassen(Matriz<unsigned int> &A, Matriz<unsigned int> &B, Matriz<unsigned int> &C, unsigned int tam)
{
    if (tam == 2)
    {
        C.prodMatriz(A,B);
    }
    else
        {
        unsigned int newTam = tam/2;
        Matriz<unsigned int> a11(newTam);
        Matriz<unsigned int> a12(newTam);
        Matriz<unsigned int> a21(newTam);
        Matriz<unsigned int> a22(newTam);
        Matriz<unsigned int> b11(newTam);
        Matriz<unsigned int> b12(newTam);
        Matriz<unsigned int> b21(newTam);
        Matriz<unsigned int> b22(newTam);
        Matriz<unsigned int> c11(newTam);
        Matriz<unsigned int> c12(newTam);
        Matriz<unsigned int> c21(newTam);
        Matriz<unsigned int> c22(newTam);
        Matriz<unsigned int> I(newTam);
        Matriz<unsigned int> II(newTam);
        Matriz<unsigned int> III(newTam);
        Matriz<unsigned int> IV(newTam);
        Matriz<unsigned int> V(newTam);
        Matriz<unsigned int> VI(newTam);
        Matriz<unsigned int> VII(newTam);

        Matriz<unsigned int> aux1(newTam);
        Matriz<unsigned int> aux2(newTam);

        unsigned int f, c;

        //DIVISION EN 4 SUBMATRICES
        for (f=0; f<newTam; f++) {
            for (c=0; c<newTam; c++)
            {
                a11.crearCuadrante(A,f,c,f,c);
                a12.crearCuadrante(A,f,c,f,c+newTam);
                a21.crearCuadrante(A,f,c,f+newTam,c);
                a22.crearCuadrante(A,f,c,f+newTam,c+newTam);

                b11.crearCuadrante(B,f,c,f,c);
                b12.crearCuadrante(B,f,c,f,c+newTam);
                b21.crearCuadrante(B,f,c,f+newTam,c);
                b22.crearCuadrante(B,f,c,f+newTam,c+newTam);

            }

        }

        //CALCULO DE I A VII
        aux1.sumaMatriz(a11,a22);
        aux2.sumaMatriz(b11,b22);
        strassen(aux1,aux2,I,newTam);

        aux1.sumaMatriz(a21,a22);
        strassen(aux1,b11,II,newTam);

        aux2.restaMatriz(b12,b22);
        strassen(a11,aux2,III,newTam);

        aux2.restaMatriz(b21,b11);
        strassen(a22,aux2,IV,newTam);

        aux1.sumaMatriz(a11,a12);
        strassen(aux1,b22,V,newTam);

        aux1.restaMatriz(a21,a11);
        aux2.sumaMatriz(b11,b12);
        strassen(aux1,aux2,VI,newTam);

        aux1.restaMatriz(a12,a22);
        aux2.sumaMatriz(b21,b22);
        strassen(aux1,aux2,VII,newTam);

        //CALCULO DE SUBMATRICES DE C

        c12.sumaMatriz(III,V);
        c21.sumaMatriz(II,IV);

        aux1.sumaMatriz(I,IV);
        aux2.sumaMatriz(aux1,VII);
        c11.restaMatriz(aux2,V);

        aux1.sumaMatriz(I,III);
        aux2.sumaMatriz(aux1, VI);
        c22.restaMatriz(aux2,II);

        //ARMADO DE LA MATRIZ RESULTANTE C

        for (f=0;f<newTam;f++) {
            for (c=0;c<newTam;c++)
            {
                C.crearCuadrante(c11,f,c,f,c);
                C.crearCuadrante(c12,f,c+newTam,f,c);
                C.crearCuadrante(c21,f+newTam,c,f,c);
                C.crearCuadrante(c22,f+newTam,c+newTam,f,c);
            }
        }
    }
}


/*----------------------------------------------------------------------------------------------------------------------*/


int main() {

    cout << "Ingrese potencia de matriz 2^k x 2^k: " << endl;

    unsigned int tam, a;

    cin >> a ;
    cout << endl;

    tam=pow(2,a);

    //SE DEFINE LA MATRIZ A
    Matriz<unsigned int> A(tam);
    cargarMatriz(A);

    //SE DEFINE LA MATRIZ B = A
    Matriz<unsigned int> B(tam);
    cargarMatriz(B);

    //SE DEFINE LA MATRIZ C
    Matriz<unsigned int> C(tam);

    //SE IMPRIME LA MATRIZ A
    cout << "Matriz A:" << endl;
    imprimirMatriz(A);
    cout << endl;

    //SE IMPRIME LA MATRIZ B
    cout << "Matriz B:" << endl;
    imprimirMatriz(B);
    cout << endl;

    //SE APLICA STRASSEN
    strassen(A,B,C,tam);

    //SE IMPRIME LA MATRIZ C
    cout << "Matriz C:" << endl;
    imprimirMatriz(C);
    cout << endl;

    //SE CREA Y IMPRIME OTRA MATRIZ D QUE UTILIZA LA FUNCION DE MULTIPLICAR NORMAL
    //PARA VERIFICAR RESULTADO
    Matriz<unsigned int> D(tam);
    cout << "Matriz D:" << endl;
    D.prodMatriz(A,B);
    imprimirMatriz(D);
    cout << endl;

    return 0;
}
