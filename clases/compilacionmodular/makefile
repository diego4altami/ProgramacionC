#Este es un ejemplo para  la compilación modular automática utilizando MAKE

#Para lograr mi objetivo del ejecutable formulas.exe hago esto

ejecutable.exe: formulas.o funciones1.o funciones2.o defTipos.h
	gcc formulas.o funciones1.o funciones2.o -o ejecutable.exe -lm

#Para lograr el objetivo del objeto formulas.o hago esto 

formulas.o: formulas.c 
	gcc -c formulas.c

#Para lograr el objetivo del objeto funciones1.o hago esto

funciones1.o: funciones1.c
	gcc -c funciones1.c 

#Para lograr el objetivo del objeto funciones2.o hago esto

funciones2.o: funciones2.c
	gcc -c funciones2.c 