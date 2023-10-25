#Este es un ejemplo para  la compilación modular automática utilizando MAKE

#Para lograr mi objetivo del arbolDeEntero formulas.exe hago esto

arbolDeEntero.exe: arbolDeEntero.o funciones.o deftipos.h
	gcc arbolDeEntero.o funciones.o -o arbolDeEntero.exe 

#Para lograr el objetivo del objeto arbolDeEntero.o hago esto 

arbolDeEntero.o: arbolDeEntero.c 
	gcc -c arbolDeEntero.c

#Para lograr el objetivo del objeto funciones.o hago esto

funciones.o: funciones.c
	gcc -c funciones.c 
