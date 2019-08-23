#include "Amazonas.h"

Amazonas::Amazonas()
//CONSTRUCTOR DE LA CLASE
{
    tablero = new char * [10];
    for (int f = 0; f < 10; f++)
        tablero[f] = new char[10];

    for (int f=0; f < 10; f++)
        for (int c=0; c < 10; c++)
            tablero[f][c]= '-';

    map <int, posiciones> casillaOcupada;

    casilleros['R'] = casillaOcupada;
    casilleros['A'] = casillaOcupada;
    casilleros['X'] = casillaOcupada;

    posiciones aux;

    map< char, map <int, posiciones> >::iterator it = casilleros.find('A');

    posicionesIniciales[0].x = 0;
    posicionesIniciales[0].y = 6;
    tablero[6][0] = 'A';

    aux.x = 0;
    aux.y = 6;

    it->second[0] = aux;

    posicionesIniciales[1].x = 3;
    posicionesIniciales[1].y = 9;
    tablero[9][3] = 'A';

    aux.x = 3;
    aux.y = 9;

    it->second[1] = aux;

    posicionesIniciales[2].x = 6;
    posicionesIniciales[2].y = 9;
    tablero[9][6] = 'A';

    aux.x = 6;
    aux.y = 9;

    it->second[2] = aux;

    posicionesIniciales[3].x = 9;
    posicionesIniciales[3].y = 6;
    tablero[6][9] = 'A';

    aux.x = 9;
    aux.y = 6;

    it->second[3] = aux;

    it = casilleros.find('R');

    posicionesIniciales[4].x = 0;
    posicionesIniciales[4].y = 3;
    tablero[3][0] = 'R';

    aux.x = 0;
    aux.y = 3;

    it->second[4] = aux;

    posicionesIniciales[5].x = 3;
    posicionesIniciales[5].y = 0;
    tablero[0][3] = 'R';

    aux.x = 3;
    aux.y = 0;

    it->second[5] = aux;

    posicionesIniciales[6].x = 6;
    posicionesIniciales[6].y = 0;
    tablero[0][6] = 'R';

    aux.x = 6;
    aux.y = 0;

    it->second[6] = aux;

    posicionesIniciales[7].x = 9;
    posicionesIniciales[7].y = 3;
    tablero[3][9] = 'R';

    aux.x = 9;
    aux.y = 3;

    it->second[7] = aux;
}

void Amazonas::obtenerTablero(char ** otroTablero) const
//ESTA FUNCION OBSERVADORA CARGA UNA MATRIZ PASADA POR PARAMETRO
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            otroTablero[i][j] = tablero[i][j];
}

int Amazonas::obtenerPuntaje() const
//ESTA FUNCION OBSERVADORA RETORNA LA CANTIDAD DE PUNTOS QUE SE PUEDEN GANAR AL SER LLAMADA
{
    return (100 - obtenerMarcados());
}

int Amazonas::obtenerMarcados() const
//ESTA FUNCION OBSERVADORA RETORNA LA CANTIDAD DE CASILLEROS OCUPADOS EN EL JUEGO
{
    int contador = 0;

    map < char, map <int, posiciones > >::const_iterator it = casilleros.begin();

    while (it != casilleros.end())
    {
        contador+=it->second.size();
        it++;
    }

    return contador;
}


bool Amazonas::existePieza(char jugador, int x, int y) const
//ESTA FUNCION OBSERVADORA RETORNA UN VALOR DE VERDAD QUE DEPENDE SI EXISTE O NO LA PIEZA EN LA POSICION INDICADA
{
    bool existe = false;

    map <char, map <int, posiciones> >::const_iterator it = casilleros.find(jugador);

    map<int, posiciones>::const_iterator itP = it->second.begin();

    while (itP != it->second.end() && (itP->second.x != x) && (itP->second.y != y))
        itP++;

    if ((itP->second.x == x) && (itP->second.y == y))
        existe = true;

    return existe;
}

bool Amazonas::juegoTerminado()
//ESTA FUNCION RETORNA UN VALOR DE VERDAD DEPENDIENDO SI SE PUEDEN SEGUIR REALIZANDO MOVIMIENTOS O NO
{
    bool terminado = false;

    return terminado;
}

bool Amazonas::movimientoPermitido(int xO, int yO, int xD, int yD) const
//ESTA FUNCION RETORNA UN VALOR DE VERDAD QUE DEPENDE DE SI EL MOVIMIENTO DEL JUGADOR ES VALIDO

{
    bool movimientoValido = false;

    return movimientoValido;
}

Amazonas::~Amazonas()
//DESTRUCTOR DE LA CLASE
{
    for (int f = 0; f < 10; f++)
        delete [] tablero[f];
    delete [] tablero;
    tablero = 0;
}
