Algoritmo Elecciones
    Definir candidatos, partidos Como Cadena
    Definir votos Como Entero
    Definir repite Como Caracter
    Definir i, j Como Entero
	
    Dimension candidatos(6)
    Dimension partidos(6)
    Dimension votos(6,6)
	
    partidos(1) <- "Partido A"
    partidos(2) <- "Partido B"
    partidos(3) <- "Partido C"
    partidos(4) <- "Partido D"
    partidos(5) <- "Partido E"
	
    repite <- "s"
	
    Mientras repite = "s" o repite = "S" Hacer
        ingresarCandidatos(candidatos)
        generarVotos(votos)
        mostrarResultados(partidos, candidatos, votos)
        calcularGanador(candidatos, votos)
        
        Escribir "¿Desea realizar otra elección? (s/n): " Sin Saltar
        Leer repite
    FinMientras
FinAlgoritmo

SubProceso ingresarCandidatos(candidatos Por Referencia)
    Definir i Como Entero
    Para i <- 1 Hasta 5 Hacer
        Escribir "Ingrese el nombre del candidato ", i, ": " Sin Saltar
        Leer candidatos(i)
    FinPara
FinSubProceso

SubProceso generarVotos(votos Por Referencia)
    Definir votos_restantes, i, j Como Entero
    
    Para j <- 1 Hasta 5 Hacer  // Se itera por rondas (columnas)
        votos_restantes <- 50  // Se asegura que cada ronda tenga 50 votos disponibles
        
        Para i <- 1 Hasta 4 Hacer  // Se distribuyen los votos entre los primeros 4 candidatos
            votos(i, j) <- Aleatorio(0, votos_restantes)
            votos_restantes <- votos_restantes - votos(i, j)
        FinPara
        
        votos(5, j) <- votos_restantes // El último candidato recibe los votos restantes para asegurar la suma de 50
    FinPara
FinSubProceso

SubProceso mostrarResultados(partidos, candidatos, votos)
    Definir total, i, j Como Entero
    Escribir "Resultados de la elección:"
    Escribir "--------------------------------------------------"
    Escribir "Partido    | Candidato | Ronda 1 | Ronda 2 | Ronda 3 | Ronda 4 | Ronda 5 | Total"
    Escribir "--------------------------------------------------"
	
    Para i <- 1 Hasta 5 Hacer
        total <- 0
        Escribir partidos(i), " | ", candidatos(i), " | " Sin Saltar
        Para j <- 1 Hasta 5 Hacer
            Escribir votos(i, j), " | " Sin Saltar
            total <- total + votos(i, j)
        FinPara
        Escribir total
    FinPara
FinSubProceso

SubProceso calcularGanador(candidatos, votos)
    Definir maxVotos, minVotos, total, i, j Como Entero
    Definir ganador, perdedor Como Cadena
    maxVotos <- 0
    minVotos <- 250
	
    Para i <- 1 Hasta 5 Hacer
        total <- 0
        Para j <- 1 Hasta 5 Hacer
            total <- total + votos(i, j)
        FinPara
        
        Si total > maxVotos Entonces
            maxVotos <- total
            ganador <- candidatos(i)
        FinSi
        
        Si total < minVotos Entonces
            minVotos <- total
            perdedor <- candidatos(i)
        FinSi
    FinPara
    
    Escribir "El ganador de la elección es: ", ganador, " con ", maxVotos, " votos."
    Escribir "El candidato con menos votos es: ", perdedor, " con ", minVotos, " votos."
FinSubProceso