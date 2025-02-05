// Este programa es una calculadora de masa corporal
// Febrero 2025 Angoly Araujo
#include <iostream>
using namespace std;

int main()
{
    // Variables
    float pesoEnLibras = 0;
    float pesoEnKilogramos = 0;
    float alturaEnPulgadas = 0;
    float alturaEnMetros = 0;
    float resultadoCalculadora = 0;
    int opcionSeleccionada = 0;
    char salidaMenu;

    // Inicia el ciclo
    do
    {

        cout << "     Calculadora de BMI        " << endl;
        cout << "1. Utilizar el Peso en Kilogramos y Altura en Metros" << endl;
        cout << "2. Utilizar el Peso en Libras y Altura en Pulgadas" << endl;
        cout << "===================================" << endl;
        cout << "Dependiendo el resultado, le indicará su condición:" << endl;
        cout << "Bajo peso:    menos de 18.5" << endl;
        cout << "Normal:       entre 18.5 y 24.9" << endl;
        cout << "Sobrepeso:    entre 25 y 29.9" << endl;
        cout << "Obeso:        30 o mas" << endl;
        cout << "===================================" << endl;
        cout << "   Opcion: ";
        cin >> opcionSeleccionada;

        // Estructuras condicionales corregidas
        if (opcionSeleccionada == 1)
        {
            cout << "Ingrese su peso en Kilogramos: ";
            cin >> pesoEnKilogramos;
            cout << "Ingrese su altura en Metros: ";
            cin >> alturaEnMetros;
            resultadoCalculadora = pesoEnKilogramos / (alturaEnMetros * alturaEnMetros);
        }
        else if (opcionSeleccionada == 2)
        {
            cout << "Ingrese su peso en Libras: ";
            cin >> pesoEnLibras;
            cout << "Ingrese su altura en Pulgadas: ";
            cin >> alturaEnPulgadas;
            resultadoCalculadora = (pesoEnLibras * 703) / (alturaEnPulgadas * alturaEnPulgadas);
        }
        else
        {
            cout << "Error: opción seleccionada no válida" << endl;
            continue; // Evita que muestre un resultado incorrecto
        }

        // Mostrar resultado y clasificación del BMI
        cout << "Su indice de masa corporal (BMI) es: " << resultadoCalculadora << endl;
        if (resultadoCalculadora < 18.5)
            cout << "Clasificacion: Bajo peso" << endl;
        else if (resultadoCalculadora >= 18.5 && resultadoCalculadora <= 24.9)
            cout << "Clasificacion: Normal" << endl;
        else if (resultadoCalculadora >= 25 && resultadoCalculadora <= 29.9)
            cout << "Clasificacion: Sobrepeso" << endl;
        else
            cout << "Clasificacion: Obeso" << endl;

        cout << "Desea realizar otra operacion Si=S o No=N" << endl;
        cin >> salidaMenu;
    } while (salidaMenu == 's' || salidaMenu == 'S');

    return 0;
}
