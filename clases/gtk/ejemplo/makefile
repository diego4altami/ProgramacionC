#Para lograr mi objetivo del ejetucable petsGTK.exe hago esto

petsGTK.exe: petsGTK.o funGTK.o funC.o
	gcc petsGTK.o funGTK.o funC.o -o petsGTK.exe `pkg-config --libs gtk+-2.0`

petsGTK.o: petsGTK.c funC.c funGTK.c
	gcc -c petsGTK.c funC.c funGTK.c `pkg-config --cflags gtk+-2.0`