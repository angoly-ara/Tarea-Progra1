// Programa para cálcular los promedios de 3 distintas facultades
// Febrero 2025 Grupo 3
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip> // Para setw y formateo de salida

using namespace std;

// Declaración de Constantes
#define NUMEROALUMNOS 5
#define NUMERONOTAS 4
#define MAX_CALIFICACION 100
#define MIN_CALIFICACION 0
#define MAX_LONGITUD_CADENA 100

// Declaración de Prototipos de Función
void LlamarCiclo();
void InicializarMatriz(float matriz[NUMEROALUMNOS][NUMERONOTAS+1]);
void LlenarMatriz(float matriz[NUMEROALUMNOS][NUMERONOTAS+1]);
float imprimirMatriz(float matriz[NUMEROALUMNOS][NUMERONOTAS+1], const char alumnos[NUMEROALUMNOS][MAX_LONGITUD_CADENA], string facultad);
int busquedaAleatoriaDeNotas(int minimo, int maximo);

int main()
{
    srand(time(NULL)); // Inicializa la semilla aleatoria
    LlamarCiclo();
    return 0;
}

void LlamarCiclo()
{
    float matrizFacultad_1[NUMEROALUMNOS][NUMERONOTAS+1];
    float matrizFacultad_2[NUMEROALUMNOS][NUMERONOTAS+1];
    float matrizFacultad_3[NUMEROALUMNOS][NUMERONOTAS+1];

    char alumnosFacultad[NUMEROALUMNOS][MAX_LONGITUD_CADENA] = {"Carlos", "Luis", "Maria", "Pedro", "Mario"};

    cout << "* Comparativo de Facultades *\n" << endl;

    // Inicializar matrices
    InicializarMatriz(matrizFacultad_1);
    InicializarMatriz(matrizFacultad_2);
    InicializarMatriz(matrizFacultad_3);

    // Llenar matrices con notas aleatorias
    LlenarMatriz(matrizFacultad_1);
    LlenarMatriz(matrizFacultad_2);
    LlenarMatriz(matrizFacultad_3);

    // Imprimir matrices y obtener promedios por facultad
    float promedioFacultad_1 = imprimirMatriz(matrizFacultad_1, alumnosFacultad, "Facultad 1");
    float promedioFacultad_2 = imprimirMatriz(matrizFacultad_2, alumnosFacultad, "Facultad 2");
    float promedioFacultad_3 = imprimirMatriz(matrizFacultad_3, alumnosFacultad, "Facultad 3");

    // Calcular mayor, menor y promedio general
    float mayorPromedio = max(promedioFacultad_1, max(promedioFacultad_2, promedioFacultad_3));
    float menorPromedio = min(promedioFacultad_1, min(promedioFacultad_2, promedioFacultad_3));
    float promedioGeneral = (promedioFacultad_1 + promedioFacultad_2 + promedioFacultad_3) / 3;

    cout << "\n=========================================";
    cout << "\n| Mayor Promedio   : " << setw(10) << mayorPromedio << " |";
    cout << "\n| Menor Promedio   : " << setw(10) << menorPromedio << " |";
    cout << "\n| Promedio General : " << setw(10) << promedioGeneral << " |";
    cout << "\n=========================================" << endl;
}

void InicializarMatriz(float matriz[NUMEROALUMNOS][NUMERONOTAS+1])
{
    for (int i = 0; i < NUMEROALUMNOS; i++)
    {
        for (int j = 0; j < NUMERONOTAS+1; j++)
        {
            matriz[i][j] = 0.00;
        }
    }
}

void LlenarMatriz(float matriz[NUMEROALUMNOS][NUMERONOTAS+1])
{
    for (int i = 0; i < NUMEROALUMNOS; i++)
    {
        float suma = 0;
        for (int j = 0; j < NUMERONOTAS; j++)
        {
            int calificacionAlumno = 0;
            if (j == 0 || j == 3) // Primer parcial y actividades
            {
                calificacionAlumno = busquedaAleatoriaDeNotas(MIN_CALIFICACION, 20);
            }
            else if (j == 1) // Segundo parcial
            {
                calificacionAlumno = busquedaAleatoriaDeNotas(MIN_CALIFICACION, 25);
            }
            else if (j == 2) // Examen final
            {
                calificacionAlumno = busquedaAleatoriaDeNotas(MIN_CALIFICACION, 35);
            }
            suma += (float)calificacionAlumno;
            matriz[i][j] = (float)calificacionAlumno;
        }
        matriz[i][NUMERONOTAS] = suma; // Última columna almacena la suma total
    }
}

float imprimirMatriz(float matriz[NUMEROALUMNOS][NUMERONOTAS+1], const char alumnos[NUMEROALUMNOS][MAX_LONGITUD_CADENA], string facultad)
{
    cout << "\n===== " << facultad << " =====\n";
    cout << "Alumno       | Nota1 | Nota2 | Nota3 | Nota4 | Total  |\n";
    cout << "------------------------------------------------------\n";

    float totalGeneral = 0;

    for (int i = 0; i < NUMEROALUMNOS; i++)
    {
        cout << left << setw(12) << alumnos[i] << "| ";
        for (int j = 0; j < NUMERONOTAS+1; j++)
        {
            cout << setw(6) << matriz[i][j] << "| ";
        }
        cout << endl;
        totalGeneral += matriz[i][NUMERONOTAS];
    }

    float promedioFacultad = totalGeneral / NUMEROALUMNOS;

    cout << "------------------------------------------------------\n";
    cout << "Promedio Facultad: " << promedioFacultad << "\n";

    return promedioFacultad;
}

int busquedaAleatoriaDeNotas(int minimo, int maximo)
{
    return minimo + rand() % (maximo - minimo + 1);
}
