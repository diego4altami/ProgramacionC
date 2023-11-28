#Para lograr mi objetivo del ejetucable text.exe hago esto

text2.exe: text2.o
	gcc text2.o -o text2.exe `pkg-config --libs gtk+-2.0`

text2.o: text2.c
	gcc -c text2.c `pkg-config --cflags gtk+-2.0`