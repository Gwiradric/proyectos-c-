#ifndef AMAZONAS_H
#define AMAZONAS_H

#include <map>

using namespace std;

class Amazonas
{
    public:
        Amazonas();
        void obtenerTablero(char ** ) const;
        int obtenerPuntaje() const;
        int obtenerMarcados() const;
        bool existePieza(char, int, int) const;
        bool movimientoPermitido(int, int, int, int) const;

        bool juegoTerminado();
        moverPiezasJugador(char, int, int, int);

        virtual ~Amazonas();

    protected:

    private:
        //ESTRUCTURA PARA LAS POSICIONES EN EL MAPA
        struct posiciones {
            int x;
            int y;
        };

        //TABLERO DE JUEGO
        char ** tablero;

        //POSICION INICIAL DE LAS PIEZAS
        posiciones posicionesIniciales[8];

        //MAPA DE MAPAS CON LAS POSICIONES DE LAS PIEZAS ROJAS, AZULES Y EQUIS
        map< char, map <int, posiciones> > casilleros;

};

#endif // AMAZONAS_H
