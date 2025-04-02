#include "Juego.h"
#include <iostream>
#include <fstream>
#include <unistd.h>

int Juego::aleatorio_en_rango(int minimo, int maximo) {
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

int Juego::filaAleatoria() {
    return this->aleatorio_en_rango(0, this->tablero.getAlturaTablero() - 1);
}

int Juego::columnaAleatoria() {
    return this->aleatorio_en_rango(0, this->tablero.getAnchoTablero() - 1);
}

// Constructor con nombreJugador
Juego::Juego(Tablero tablero, int cantidadMinas, std::string nombreJugador)
    : tablero(tablero), cantidadMinas(cantidadMinas), nombreJugador(nombreJugador) {
    this->colocarMinasAleatoriamente();
}

// Nueva sobrecarga del constructor sin nombreJugador
Juego::Juego(Tablero tablero, int cantidadMinas)
    : tablero(tablero), cantidadMinas(cantidadMinas), nombreJugador("Jugador Anónimo") {
    this->colocarMinasAleatoriamente();
}

void Juego::colocarMinasAleatoriamente() {
    int x, y, minasColocadas = 0;
    while (minasColocadas < this->cantidadMinas) {
        x = this->columnaAleatoria();
        y = this->filaAleatoria();
        if (this->tablero.colocarMina(x, y)) {
            minasColocadas++;
        }
    }
}

int Juego::solicitarFilaUsuario() {
    int fila = 0;
    std::cout << "Ingresa la FILA en la que desea jugar: ";
    std::cin >> fila;
    return fila - 1;
}

int Juego::solicitarColumnaUsuario() {
    int columna = 0;
    std::cout << "Ingresa la COLUMNA en la que desea jugar: ";
    std::cin >> columna;
    return columna - 1;
}

bool Juego::jugadorGana() {
    int conteo = this->tablero.contarCeldasSinMinasYSinDescubrir();
    return (conteo == 0);
}

void Juego::iniciar() {
    int fila, columna;
    while (true) {
        this->tablero.imprimir();
        fila = this->solicitarFilaUsuario();
        columna = this->solicitarColumnaUsuario();
        bool respuestaAUsuario = this->tablero.descubrirMina(columna, fila);

        if (!respuestaAUsuario) {
            std::cout << "Lo siento, " << nombreJugador << ", perdiste el juego.\n";
            this->tablero.setModoDesarrollador(true);
            this->tablero.imprimir();
            break;
        }

        if (this->jugadorGana()) {
            std::cout << "¡Felicidades, " << nombreJugador << "! Has ganado el juego.\n";
            this->tablero.setModoDesarrollador(true);
            this->tablero.imprimir();
            break;
        }
    }
}


