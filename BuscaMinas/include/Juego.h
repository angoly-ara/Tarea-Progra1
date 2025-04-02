#ifndef JUEGO_H
#define JUEGO_H
#include "Tablero.h"
#include <string>

class Juego {
private:
    Tablero tablero;
    int cantidadMinas;
    std::string nombreJugador;

    int aleatorio_en_rango(int minimo, int maximo);
    int filaAleatoria();
    int columnaAleatoria();

public:
    Juego(Tablero tablero, int cantidadMinas); // Nueva sobrecarga sin nombreJugador
    Juego(Tablero tablero, int cantidadMinas, std::string nombreJugador);

    void colocarMinasAleatoriamente();
    int solicitarFilaUsuario();
    int solicitarColumnaUsuario();
    bool jugadorGana();
    void iniciar();
};

#endif // JUEGO_H
