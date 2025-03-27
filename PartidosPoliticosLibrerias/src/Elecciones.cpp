// Partidos Politicos implentando Librerias
// Marzo 2025 Angoly Araujo
#include "Elecciones.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Elecciones::Elecciones() {
    partidos[0] = "Partido A";
    partidos[1] = "Partido B";
    partidos[2] = "Partido C";
    partidos[3] = "Partido D";
    partidos[4] = "Partido E";
    srand(time(0));
    // Inicializamos los votos con cero
    for (int i = 0; i < NUM_CANDIDATOS; i++) {
        for (int j = 0; j < NUM_RONDAS; j++) {
            votos[i][j] = 0;
        }
    }
}

void Elecciones::ingresarCandidatos() {
    cout << "Ingrese los nombres de los " << NUM_CANDIDATOS << " candidatos:" << endl;
    for (int i = 0; i < NUM_CANDIDATOS; i++) {
        cout << "Candidato " << i + 1 << ": ";
        cin >> candidatos[i];
    }
}

void Elecciones::generarVotos() {
    for (int r = 0; r < NUM_RONDAS; r++) {
        int votos_restantes = NUM_VOTANTES;
        for (int c = 0; c < NUM_CANDIDATOS - 1; c++) {
            votos[c][r] = rand() % (votos_restantes + 1);
            votos_restantes -= votos[c][r];
        }
        votos[NUM_CANDIDATOS - 1][r] = votos_restantes;
    }
}

void Elecciones::mostrarResultados() {
    cout << "\nResultados de la eleccion:\n";
    cout << "--------------------------------------------------\n";
    cout << "Partido    | Candidato ";
    for (int r = 0; r < NUM_RONDAS; r++) {
        cout << "| Ronda " << r + 1 << " ";
    }
    cout << "| Total\n";
    cout << "--------------------------------------------------\n";

    int sumaRondas[NUM_RONDAS] = {0};

    for (int c = 0; c < NUM_CANDIDATOS; c++) {
        cout << partidos[c] << " | " << candidatos[c] << " \t";
        int total = 0;
        for (int r = 0; r < NUM_RONDAS; r++) {
            cout << "| " << votos[c][r] << " \t";
            total += votos[c][r];
            sumaRondas[r] += votos[c][r];
        }
        cout << "| " << total << "\n";
    }

    cout << "--------------------------------------------------\n";
    cout << "Votos por ronda  ";
    for (int r = 0; r < NUM_RONDAS; r++) {
        cout << "| " << sumaRondas[r] << " \t";
    }
    cout << "|";
}

void Elecciones::calcularGanador() {
    int maxVotos = 0, minVotos = NUM_VOTANTES * NUM_RONDAS;
    string ganador, perdedor;

    for (int c = 0; c < NUM_CANDIDATOS; c++) {
        int total = 0;
        for (int r = 0; r < NUM_RONDAS; r++) {
            total += votos[c][r];
        }

        if (total > maxVotos) {
            maxVotos = total;
            ganador = candidatos[c];
        }

        if (total < minVotos) {
            minVotos = total;
            perdedor = candidatos[c];
        }
    }

    cout << "\nEl ganador de la eleccion es: " << ganador << " con " << maxVotos << " votos.";
    cout << "\nEl candidato con menos votos es: " << perdedor << " con " << minVotos << " votos.\n";
}

