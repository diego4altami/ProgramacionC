#Para lograr mi objetivo del ejetucable text.exe hago esto

text.exe: text.o
	gcc text.o -o text.exe `pkg-config --libs gtk+-2.0`

text.o: text.c
	gcc -c text.c `pkg-config --cflags gtk+-2.0`