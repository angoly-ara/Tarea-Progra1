#include "Celda.h"
#include <iostream>
using namespace std;

// Constructor por defecto de la clase Celda
Celda::Celda()
{
}

// Constructor con par�metros para inicializar las coordenadas y el estado de la mina
Celda::Celda(int coordenadaX, int coordenadaY, bool estadoMina)
{
    // Inicializa las coordenadas X y Y
    this->coordenadaX = coordenadaX;
    this->coordenadaY = coordenadaY;

    // Inicializa el estado de la mina
    this->mina = estadoMina;

    // Inicializa minaDescubierta como false
    this->minaDescubierta = false;
}

// M�todo para establecer la coordenada X
int Celda::setCoordenadaX(int coordenadaX)
{
    // Asigna el valor a la coordenada X
    this->coordenadaX = coordenadaX;
}

// M�todo para obtener el valor de la coordenada X
int Celda::getCoordenadaX()
{
    // Devuelve el valor de la coordenada X
    return this->coordenadaX;
}

// M�todo para establecer la coordenada Y
int Celda::setCoordenadaY(int coordenadaY)
{
    // Asigna el valor a la coordenada Y
    this->coordenadaY = coordenadaY;
}

// M�todo para obtener el valor de la coordenada Y
int Celda::getCoordenadaY()
{
    // Devuelve el valor de la coordenada Y
    return this->coordenadaY;
}

// M�todo para establecer el estado de la mina, solo si no hay una mina ya puesta
bool Celda::setMina(bool estadoMina)
{
    // Verifica si ya hay una mina en la celda
    if (this->getMina())
    {
        // Si ya hay una mina, no permite cambiar su estado
        return false;
    }
    else{
        // Si no hay mina, establece el nuevo estado
        this->mina = estadoMina;
        return true;
    }
}

// M�todo para obtener el estado de la mina
bool Celda::getMina()
{
    // Devuelve si la celda tiene mina o no
    return this->mina;
}

// M�todo para establecer si la mina ha sido descubierta
bool Celda::setMinaDescubierta(bool minaDescubierta)
{
    // Establece si la mina ha sido descubierta
    this->minaDescubierta = minaDescubierta;
}

// M�todo para obtener el estado de la mina descubierta
bool Celda::getMinaDescubierta()
{
    // Devuelve si la mina ha sido descubierta
    return this->minaDescubierta;
}

// M�todo para imprimir la informaci�n de la celda
void Celda::imprimirCelda()
{
    // Muestra las coordenadas y el estado de la mina
    cout << "Celda en " << this->coordenadaX << ", " << this->coordenadaY << " con mina? " << this->mina << "\n";
}
