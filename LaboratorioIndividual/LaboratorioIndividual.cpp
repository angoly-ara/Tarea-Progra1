//Laboratorio Individual Ejercicio Impar
// 18 de febrero 2025 Camila Araujo
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Definici�n de constantes
#define NUM_CANDIDATOS 5
#define NUM_VOTANTES 50
#define NUM_RONDAS 5

// Declaraci�n de prototipos de funciones
void ingresarCandidatos(string candidatos[]);
void generarVotos(int votos[][NUM_RONDAS]);
void mostrarResultados(string partidos[], string candidatos[], int votos[][NUM_RONDAS]);
void calcularGanador(string candidatos[], int votos[][NUM_RONDAS]);

// Funci�n principal del programa
int main() {
    srand(time(0)); // Inicializa la semilla para generaci�n de n�meros aleatorios
    string candidatos[NUM_CANDIDATOS];
    string partidos[NUM_CANDIDATOS] = {"Partido A", "Partido B", "Partido C", "Partido D", "Partido E"};
    int votos[NUM_CANDIDATOS][NUM_RONDAS] = {0};

    char repetir;
    do {
        ingresarCandidatos(candidatos); // Solicita los nombres de los candidatos
        generarVotos(votos); // Genera votos de manera aleatoria asegurando 50 por ronda
        mostrarResultados(partidos, candidatos, votos); // Muestra los resultados de cada ronda
        calcularGanador(candidatos, votos); // Calcula el ganador y el perdedor

        cout << "\nDesea realizar otra eleccion? (s/n): ";
        cin >> repetir;
    } while (repetir == 's' || repetir == 'S');

    return 0;
}

// Funci�n para ingresar los nombres de los candidatos
void ingresarCandidatos(string candidatos[]) {
    cout << "Ingrese los nombres de los " << NUM_CANDIDATOS << " candidatos:" << endl;
    for (int i = 0; i < NUM_CANDIDATOS; i++) {
        cout << "Candidato " << i + 1 << ": ";
        cin >> candidatos[i];
    }
}

// Funci�n para generar votos aleatorios asegurando que la suma sea 50 por ronda
void generarVotos(int votos[][NUM_RONDAS]) {
    for (int r = 0; r < NUM_RONDAS; r++) {
        int votos_restantes = NUM_VOTANTES;
        for (int c = 0; c < NUM_CANDIDATOS - 1; c++) {
            votos[c][r] = rand() % (votos_restantes + 1);
            votos_restantes -= votos[c][r];
        }
        votos[NUM_CANDIDATOS - 1][r] = votos_restantes; // �ltimo candidato recibe los votos restantes
    }
}

// Funci�n para mostrar los resultados de la elecci�n
void mostrarResultados(string partidos[], string candidatos[], int votos[][NUM_RONDAS]) {
    cout << "\nResultados de la eleccion:\n";
    cout << "--------------------------------------------------\n";
    cout << "Partido    | Candidato ";
    for (int r = 0; r < NUM_RONDAS; r++) {
        cout << "| Ronda " << r + 1 << " ";
    }
    cout << "| Total\n";
    cout << "--------------------------------------------------\n";

    for (int c = 0; c < NUM_CANDIDATOS; c++) {
        cout << partidos[c] << " | " << candidatos[c] << " 	";
        int total = 0;
        for (int r = 0; r < NUM_RONDAS; r++) {
            cout << "| " << votos[c][r] << " 	";
            total += votos[c][r];
        }
        cout << "| " << total << "\n";
    }
}

// Funci�n para calcular el ganador y el perdedor de la elecci�n
void calcularGanador(string candidatos[], int votos[][NUM_RONDAS]) {
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
