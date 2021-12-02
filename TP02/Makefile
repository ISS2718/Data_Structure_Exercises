all: Matriz3D

Matriz3D: LDED.o main.o
	gcc -o Matriz3D LDED.o main.o

LDED.o: LDED.c
	gcc -o LDED.o -c LDED.c

main.o: main.c
	gcc -o main.o -c main.c

clear:
	rm *.o *.exe

run: 
	./Matriz3D
