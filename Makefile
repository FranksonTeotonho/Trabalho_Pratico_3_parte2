all: cg2d exemplo1

cg2d:
	gcc -c cg2d.c

exemplo1: cg2d.o 
	gcc a.c -o a cg2d.o -lm -lX11
	gcc b.c -o b cg2d.o -lm -lX11
	gcc c.c -o c cg2d.o -lm -lX11
