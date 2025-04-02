#ifndef CONFIG_H
#define CONFIG_H

#include <vector>
#include "Jugador.h"  // Asegúrate de incluir Jugador.h

class Config
{
public:
    Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero, int vidasTablero);

    int getfilasTablero();
    int setfilasTablero(int filasTablero);
    int getcolumnasTablero();
    int setcolumnasTablero(int columnasTablero);
    int getminasTablero();
    int setminasTablero(int minasTablero);
    bool getmodoDesarrolladorTablero();
    bool setmodoDesarrolladorTablero(bool modoDesarrolladorTablero);
    int getvidasTablero();
    int setvidasTablero(int vidasTablero);

    void menuConfiguracion(std::vector<Jugador>& jugadores);  // Cambio aquí para aceptar jugadores
    void mostrarJugadores(const std::vector<Jugador>& jugadores);  // Función para mostrar jugadores

protected:

private:
    int filasTablero;
    int columnasTablero;
    int minasTablero;
    bool modoDesarrolladorTablero;
    int vidasTablero;
};

#endif // CONFIG_H

