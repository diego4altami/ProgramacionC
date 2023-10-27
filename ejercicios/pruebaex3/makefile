#Este es un ejemplo para  la compilación modular automática utilizando MAKE

#Para lograr mi objetivo del aeromexico formulas.exe hago esto

aeromexico.exe: aeromexico.o funciones.o deftipos.h
	gcc aeromexico.o funciones.o -o aeromexico.exe 

#Para lograr el objetivo del objeto aeromexico.o hago esto 

aeromexico.o: aeromexico.c 
	gcc -c aeromexico.c

#Para lograr el objetivo del objeto funciones.o hago esto

funciones.o: funciones.c
	gcc -c funciones.c 
