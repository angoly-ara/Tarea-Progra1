#include "Jugador.h"

Jugador::Jugador(std::string nombre) : nombre(nombre), puntaje(0) {}

void Jugador::incrementarPuntaje() {
    puntaje += 10; // Se puede ajustar el valor seg�n la l�gica del juego
}

std::string Jugador::getNombre() const {
    return nombre;
}

int Jugador::getPuntaje() const {
    return puntaje;
}
