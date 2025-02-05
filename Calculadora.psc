Algoritmo Calculadora
		//AngolyAraujo
		// Definición de variables
		Definir cantidadNumeros Como Entero
		Definir numero, resultado Como Real
		Definir operacion Como Caracter
		Definir i Como Entero
		
		// Inicializar resultado
		resultado <- 0
		
		// Solicitar la cantidad de números a operar
		Escribir "Ingrese la cantidad de números a operar: "
		Leer cantidadNumeros
		
		// Validar que la cantidad sea mayor a 1
		Si cantidadNumeros < 2 Entonces
			Escribir "Error: Debe ingresar al menos dos números."
		FinSi

		// Solicitar la operación
		Escribir "Seleccione la operación (+, -, *, /): "
		Leer operacion

// Inicialización especial para multiplicación
		Si operacion = "*" Entonces
			resultado <- 1
		FinSi

// Proceso de acumulación
		Para i <- 1 Hasta cantidadNumeros Hacer
			Escribir "Ingrese el número ", i, ": "
			Leer numero
		
	
			Segun operacion Hacer
				"+": 
					resultado <- resultado + numero
				"-":
					Si i = 1 Entonces
						resultado <- numero  // Para la resta, el primer número se asigna directamente
					Sino
						resultado <- resultado - numero
					FinSi
				"*": 
					resultado <- resultado * numero
				"/": 
					Si i = 1 Entonces
						resultado <- numero  // El primer número se asigna directamente
					Sino
						Si numero = 0 Entonces
							Escribir "Error: No se puede dividir entre 0"
						Sino
							resultado <- resultado / numero
						FinSi
					FinSi
				De Otro Modo:
					Escribir "Operación no válida"

			FinSegun
		FinPara

// Mostrar resultado
		Escribir "Resultado: ", resultado
		
FinAlgoritmo



