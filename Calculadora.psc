Algoritmo Calculadora
		//AngolyAraujo
		// Definici�n de variables
		Definir cantidadNumeros Como Entero
		Definir numero, resultado Como Real
		Definir operacion Como Caracter
		Definir i Como Entero
		
		// Inicializar resultado
		resultado <- 0
		
		// Solicitar la cantidad de n�meros a operar
		Escribir "Ingrese la cantidad de n�meros a operar: "
		Leer cantidadNumeros
		
		// Validar que la cantidad sea mayor a 1
		Si cantidadNumeros < 2 Entonces
			Escribir "Error: Debe ingresar al menos dos n�meros."
		FinSi

		// Solicitar la operaci�n
		Escribir "Seleccione la operaci�n (+, -, *, /): "
		Leer operacion

// Inicializaci�n especial para multiplicaci�n
		Si operacion = "*" Entonces
			resultado <- 1
		FinSi

// Proceso de acumulaci�n
		Para i <- 1 Hasta cantidadNumeros Hacer
			Escribir "Ingrese el n�mero ", i, ": "
			Leer numero
		
	
			Segun operacion Hacer
				"+": 
					resultado <- resultado + numero
				"-":
					Si i = 1 Entonces
						resultado <- numero  // Para la resta, el primer n�mero se asigna directamente
					Sino
						resultado <- resultado - numero
					FinSi
				"*": 
					resultado <- resultado * numero
				"/": 
					Si i = 1 Entonces
						resultado <- numero  // El primer n�mero se asigna directamente
					Sino
						Si numero = 0 Entonces
							Escribir "Error: No se puede dividir entre 0"
						Sino
							resultado <- resultado / numero
						FinSi
					FinSi
				De Otro Modo:
					Escribir "Operaci�n no v�lida"

			FinSegun
		FinPara

// Mostrar resultado
		Escribir "Resultado: ", resultado
		
FinAlgoritmo



