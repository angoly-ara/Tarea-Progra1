// Partidos Politicos implentando Librerias
// Marzo 2025 Angoly Araujo
#ifndef ELECCIONES_H
#define ELECCIONES_H

#include <string>
using namespace std;

#define NUM_CANDIDATOS 5
#define NUM_VOTANTES 50
#define NUM_RONDAS 5

class Elecciones {
private:
    string candidatos[NUM_CANDIDATOS];
    string partidos[NUM_CANDIDATOS];
    int votos[NUM_CANDIDATOS][NUM_RONDAS];

public:
    Elecciones();  // Constructor
    void ingresarCandidatos();
    void generarVotos();
    void mostrarResultados();
    void calcularGanador();
};

#endif

