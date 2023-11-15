petsGTK.exe: petsGTK.o 
	gcc -o petsGTK.exe petsGTK.o `pkg-config --libs gtk+-2.0`

petsGTK.o: petsGTK.c 
	gcc -c petsGTK.c `pkg-config --cflags gtk+-2.0`

clean: 
	rm *.o