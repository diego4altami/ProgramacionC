#Este es un ejemplo para  la compilación modular automática utilizando MAKE

#Para lograr mi objetivo del listaDoble formulas.exe hago esto

listaDoble.exe: listaDoble.o funciones.o tiposDoble.h
	gcc listaDoble.o funciones.o -o listaDoble.exe 

#Para lograr el objetivo del objeto listaDoble.o hago esto 

listaDoble.o: listaDoble.c 
	gcc -c listaDoble.c

#Para lograr el objetivo del objeto funciones.o hago esto

funciones.o: funciones.c
	gcc -c funciones.c 
