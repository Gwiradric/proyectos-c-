#include <iostream>
#include <map>
#include "Amazonas.h"

using namespace std;

void borrarTablero(char ** otroTablero)
//ESTA FUNCION LIBERA MEMORIA DE LA MATRIZ USADA PARA IMPRIMIR EL TABLERO
{
    for (int f = 0; f < 10; f++)
        delete [] otroTablero[f];
    delete [] otroTablero;
    otroTablero = 0;
}

void imprimirTablero(const Amazonas & juego)
//ESTA FUNCION IMPRIME POR PANTALLA EL TABLERO DE JUEGO
{
    char ** otroTablero;

    otroTablero = new char * [10];
    for (int f = 0; f < 10; f++)
        otroTablero[f] = new char[10];

    juego.obtenerTablero(otroTablero);

    for (int i = 9; i >= 0 ; i--)
        {
        cout << i+1 << " ";
        if (i < 9)
            cout << " ";
        for (int j = 0; j < 10; j++)
            cout << otroTablero[i][j] << " ";
        cout << endl;
        }

    cout << "   A B C D E F G H I J" << endl;
    cout << endl;

    borrarTablero(otroTablero);
}

int obtenerColumna(char letra)
//ESTA FUNCION CONVIERTE EL CARACTER INGRESADO EN UN ENTERO
//ES UTILIZADO PARA LAS COLUMNAS DE LA MATRIZ
{
    int numero;
    switch(letra)
    {
        {
        case 'A':
            numero = 0;
            break;
        case 'B':
            numero = 1;
            break;
        case 'C':
            numero = 2;
            break;
        case 'D':
            numero = 3;
            break;
        case 'E':
            numero = 4;
            break;
        case 'F':
            numero = 5;
            break;
        case 'G':
            numero = 6;
        case 'H':
            numero = 7;
            break;
        case 'I':
            numero = 8;
            break;
        case 'J':
            numero = 9;
            break;
        default:
            cout << "Invalid Selection. Please try Again." << endl;
        }
    }
    return numero;
}

int ingresarProfundidad()
//FUNCION QUE DEVUELVE EL NIVEL DE PROFUNDIDAD DE EXPLORACION
{
    cout << "Ingrese la profundidad de exploracion (1 a 3): ";
    int numero;
    cin >> numero;
    cout << endl;
    return numero;
}

void ingreseHeuristica()
{
    cout << "Ingrese la heuristica que desee: " << endl;
    cout << "1 - Heuristica de FEDE" << endl;
    cout << endl;
    int numero;
    cin >> numero;
    cout << endl;
}

void mostrarMensajeMovimiento()
//IMPRIME POR PANTALLA
{
    cout << "Ingrese jugada <CO, CD, CF>" << endl;
}

void jugar(Amazonas &juego)
//FUNCION PRINCIPAL DEL JUEGO
{
    //ingresarProfundidad();
    //ingreseHeuristica();
    int turno = 0;
    char xO, xD, marcaX;
    int yO, yD, marcaY;

    cout << "Amazonas: " << endl;
    cout << endl;
    while (!juego.juegoTerminado())
    {
        imprimirTablero(juego);
        if (turno % 2 == 0)
        {
            //TURNO JUGADOR
            mostrarMensajeMovimiento();

            cin >> xO >> yO >> xD >> yD >> marcaX >> marcaY;




        }
        else
        {
            //TURNO MAQUINA
        }
        turno++;

    }
}



int main()
{
    Amazonas juego;

    jugar(juego);

    return 0;
}
