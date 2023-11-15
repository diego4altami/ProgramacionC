#Para lograr mi objetivo del ejetucable imagenosito.exe hago esto

imagenosito.exe: imagenosito.o 
	gcc imagenosito.o -o imagenosito.exe `pkg-config --libs gtk+-2.0`

#Para lograr el objetivo del objeto imagenosito.o hago esto:
imagenosito.o: imagenosito.c
	gcc -c imagenosito.c `pkg-config --cflags gtk+-2.0`
