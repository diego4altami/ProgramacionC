#Este es un ejemplo para  la compilación modular automática utilizando MAKE

#Para lograr mi objetivo del canes formulas.exe hago esto

canes.exe: canes.o funciones.o deftipos.h
	gcc canes.o funciones.o -o canes.exe 

#Para lograr el objetivo del objeto canes.o hago esto 

canes.o: canes.c 
	gcc -c canes.c

#Para lograr el objetivo del objeto funciones.o hago esto

funciones.o: funciones.c
	gcc -c funciones.c 