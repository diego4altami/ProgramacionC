appEbook.exe: appEbook.o funGTKbook.o
	gcc -o appEbook.exe appEbook.o funGTKbook.o `pkg-config --libs gtk+-2.0`

appEbook.o: appEbook.c funGTKbook.c
	gcc -c appEbook.c funGTKbook.c `pkg-config --cflags gtk+-2.0`

clean: 
	rm *.o