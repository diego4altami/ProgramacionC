appEbook.exe: appEbook.o funGTKbook.o funCbook.o
	gcc -o appEbook.exe appEbook.o funGTKbook.o funCbook.o `pkg-config --libs gtk+-2.0`

appEbook.o: appEbook.c funGTKbook.c funCbook.c
	gcc -c -g appEbook.c funGTKbook.c funCbook.c `pkg-config --cflags gtk+-2.0`

clean: 
	rm *.o