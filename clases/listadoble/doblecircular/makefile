#Este es un ejemplo para  la compilación modular automática utilizando MAKE

#Para lograr mi objetivo del listaDobleCirc formulas.exe hago esto

listaDobleCirc.exe: listaDobleCirc.o funciones.o deftipos.h
	gcc listaDobleCirc.o funciones.o -o listaDobleCirc.exe 

#Para lograr el objetivo del objeto listaDobleCirc.o hago esto 

listaDobleCirc.o: listaDobleCirc.c 
	gcc -c listaDobleCirc.c

#Para lograr el objetivo del objeto funciones.o hago esto

funciones.o: funciones.c
	gcc -c funciones.c 
