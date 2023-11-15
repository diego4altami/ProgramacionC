#Para lograr mi objetivo del ejetucable petsGTK.exe hago esto

petsGTK.exe: petsGTK.o 
	gcc petsGTK.o -o petsGTK.exe `pkg-config --libs gtk+-2.0`

#Para lograr el objetivo del objeto petsGTK.o hago esto:
petsGTK.o: petsGTK.c
	gcc -c petsGTK.c `pkg-config --cflags gtk+-2.0`
