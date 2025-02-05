Algoritmo Billetes
	
	Leer Monto
	
	Billetes100 <- trunc(Monto / 100)
	MontoRestante <- Monto - (Billetes100 * 100)
	Escribir 'Hay', Billetes100, 'Billete(s) de 100'
	
	Billetes50 <- trunc(MontoRestante / 50)
	MontoRestante <- MontoRestante - (Billetes50 * 50)
	Escribir 'Hay', Billetes50, 'Billete(s) de 50'
	
	Billetes20 <- trunc(MontoRestante / 20)
	MontoRestante <- MontoRestante - (Billetes20 * 20)
	Escribir 'Hay', Billetes20, 'Billete(s) de 20'
	
	Billetes10 <- trunc(MontoRestante / 10)
	MontoRestante <- MontoRestante - (Billetes10 * 10)
	Escribir 'Hay', Billetes10, 'Billete(s) de 10'
	
	Billetes5 <- trunc(MontoRestante / 5)
	MontoRestante <- MontoRestante - (Billetes5 * 5)
	Escribir 'Hay', Billetes5, 'Billete(s) de 5'
	
	Billetes2 <- trunc(MontoRestante / 2)
	MontoRestante <- MontoRestante - (Billetes5 * 2)
	Escribir 'Hay', Billetes2, 'Billete(s) de 2'
	
	Billetes1 <- trunc(MontoRestante / 1)
	MontoRestante <- MontoRestante - (Billetes5 * 1)
	Escribir 'Hay', Billetes1, 'Billete(s) de 1'

	
FinAlgoritmo
