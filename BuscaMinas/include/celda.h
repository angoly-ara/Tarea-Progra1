#ifndef CELDA_H
#define CELDA_H
// Librer�a que define la clase Celda para representar una celda en el juego,
// almacenando coordenadas, estado de mina y m�todos para su manipulaci�n.

class Celda
{
    public:
        // Constructor por defecto
        Celda();

        // Constructor que inicializa la celda con coordenadas y estado de mina
        Celda(int coordenadaX, int coordenadaY, bool estadoMina);

        // M�todos para establecer y obtener la coordenada X
        int setCoordenadaX(int coordenadaX);
        int getCoordenadaX();

        // M�todos para establecer y obtener la coordenada Y
        int setCoordenadaY(int coordenadaY);
        int getCoordenadaY();

        // M�todos para establecer y obtener si la celda tiene una mina
        bool setMina(bool estadoMina);
        bool getMina();

        // M�todos para establecer y obtener si la mina ha sido descubierta
        bool setMinaDescubierta(bool minaDescubierta);
        bool getMinaDescubierta();

        // M�todo para imprimir la celda (probablemente para depuraci�n o visualizaci�n)
        void imprimirCelda();

    protected:
        // Secci�n protegida (actualmente vac�a, pero �til para herencia)

    private:
        // Variables privadas que almacenan las coordenadas y estado de la celda
        int coordenadaX, coordenadaY; // Coordenadas de la celda en el tablero
        bool mina; // Indica si la celda contiene una mina
        bool minaDescubierta; // Indica si la mina ha sido descubierta
};

#endif // CELDA_H
