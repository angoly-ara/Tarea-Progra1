// Partidos Politicos implentando Librerias
// Marzo 2025 Angoly Araujo
#include <iostream>
#include "Elecciones.h"

using namespace std;

int main() {
    Elecciones elecciones;
    char repetir;
    do {
        elecciones.ingresarCandidatos();
        elecciones.generarVotos();
        elecciones.mostrarResultados();
        elecciones.calcularGanador();

        cout << "\nDesea realizar otra eleccion? (s/n): ";
        cin >> repetir;
    } while (repetir == 's' || repetir == 'S');

    return 0;
}

