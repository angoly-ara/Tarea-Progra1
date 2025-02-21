// Prueba corta 1 - Camila Araujo
// 21 de febrero 2025 - Equipos de futbol

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

//Declaraciòn de Prototipos de Funciòn
int generarGoles();
void imprimirTabla(string equipos[], int partidosJugados[], int partidosGanados[], int partidosPerdidos[], int partidosEmpatados[]);
void imprimirTablaResultados(string equipos[], int resultados[6][6]);


// Función para generar un número aleatorio entre 0 y 10
int generarGoles() {
    return rand() % 11;
}

// Función para imprimir la tabla de posiciones
void imprimirTabla(string equipos[], int partidosJugados[], int partidosGanados[], int partidosPerdidos[], int partidosEmpatados[]) {
    cout << "Tabla de POSICIONES:" << endl;
    cout << "-" << endl;
    cout << "| Equipo" << "| JUGADOS" << "| GANADOS" << "| PERDIDOS" << "| Empatados" << "| Puntos |" << endl;
    for (int i = 0; i < 6; i++) {
        int puntos = partidosGanados[i] * 3 + partidosEmpatados[i];
        cout << "| " + equipos[i] << "| " + to_string(partidosJugados[i]) << "| " + to_string(partidosGanados[i]) <<  "| " + to_string(partidosPerdidos[i]) << "| " + to_string(partidosEmpatados[i])  << "| " + to_string(puntos) + " |" << endl;
    }
}

// Función para imprimir la tabla de resultados de los partidos
void imprimirTablaResultados(string equipos[], int resultados[6][6]) {
    cout << "Tabla de resultados de los Partidos:" << endl;
    cout << "| Equipo" << "| Equipo" << "| Resultado |" << endl;
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            cout << "| " + equipos[i] << "| " + equipos[j] ;
            if (resultados[i][j] == -1) {
                cout << "| Empate |" << endl;
            } else {
                cout << "| " + to_string(resultados[i][j]) + "-" + to_string(resultados[j][i]) + " |" << endl;
            }
        }
    }
    cout << setfill('-') << setw(50) << "-" << endl;

}

int main() {
    // Apartado para que genera números aleatorios
    srand(time(0));


    // Arreglos para almacenar la información de los equipos
    string equipos[6];
    int partidosJugados[6] = {0};
    int partidosGanados[6] = {0};
    int partidosPerdidos[6] = {0};
    int partidosEmpatados[6] = {0};

    // Arreglo para almacenar los resultados de los partidos
    int resultados[6][6] = {0};

    // Ingreso de nombres de los equipos
    cout << "Ingrese los nombres de los 6 equipos:" << endl;
    for (int i = 0; i < 6; i++) {
        cout << "Equipo " << i + 1 << ": ";
        cin >> equipos[i];
    }

    // Generación de partidos
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            int golesEquipo1 = generarGoles();
            int golesEquipo2 = generarGoles();
            resultados[i][j] = golesEquipo1;
            resultados[j][i] = golesEquipo2;
            partidosJugados[i]++;
            partidosJugados[j]++;
            if (golesEquipo1 > golesEquipo2) {
                partidosGanados[i]++;
                partidosPerdidos[j]++;
            } else if (golesEquipo1 < golesEquipo2) {
                partidosGanados[j]++;
                partidosPerdidos[i]++;
            } else {
                partidosEmpatados[i]++;
                partidosEmpatados[j]++;
            }
        }
    }

    // Impresión de la tabla de resultados de los partidos
    imprimirTablaResultados(equipos, resultados);

    // Impresión de la tabla de posiciones
    imprimirTabla(equipos, partidosJugados, partidosGanados, partidosPerdidos, partidosEmpatados);


    // Cálculo del equipo ganador y del equipo perdedor de la tabla
    int maxPuntos = 0;
    int equipoGanador = -1;
    int minPuntos = 1000;
    int equipoPerdedor = -1;
    for (int i = 0; i < 6; i++) {
        int puntos = partidosGanados[i] * 3 + partidosEmpatados[i];
        if (puntos > maxPuntos) {
            maxPuntos = puntos;
            equipoGanador = i;
        }
        if (puntos < minPuntos) {
            minPuntos = puntos;
            equipoPerdedor = i;
        }
    }

    cout << "El equipo ganador es: " << equipos[equipoGanador] << endl;
    cout << "El equipo que tiene menos puntos es: " << equipos[equipoPerdedor] << endl;


    return 0;
}

