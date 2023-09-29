#Para lograr mi objetivo del ejecutable formulas.exe hago esto

ejecutable.exe: arregloReales.o sumarReales.o defTipos.h
	gcc arregloReales.o sumarReales.o -o arregloReales.exe 

#Para lograr el objetivo del objeto formulas.o hago esto 

formulas.o: arregloReales.c 
	gcc -c arregloReales.c

#Para lograr el objetivo del objeto funciones1.o hago esto

funciones1.o: sumarReales.c
	gcc -c sumarReales.c 
