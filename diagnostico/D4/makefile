#Este es un ejemplo para  la compilación modular automática utilizando MAKE

#Para lograr mi objetivo del archvioaleatorios formulas.exe hago esto

archivoaleatorios.exe: archvioaleatorios.o funciones.o deftipos.h
	gcc archvioaleatorios.o funciones.o -o archvioaleatorios.exe 

#Para lograr el objetivo del objeto archvioaleatorios.o hago esto 

archvioaleatorios.o: archvioaleatorios.c 
	gcc -c archvioaleatorios.c

#Para lograr el objetivo del objeto funciones.o hago esto

funciones.o: funciones.c
	gcc -c funciones.c 