
#Este es un ejemplo para  la compilación modular automática utilizando MAKE

#Para lograr mi objetivo del frutas hago esto

frutas.exe: frutas.o funciones.o deftipos.h
	gcc frutas.o funciones.o -o frutas.exe 

#Para lograr el objetivo del objeto frutas.o hago esto 

frutas.o: frutas.c 
	gcc -c frutas.c

#Para lograr el objetivo del objeto funciones.o hago esto

funciones.o: funciones.c
	gcc -c funciones.c 