all: Matriz3D

Matriz3D: LDED.o main.o
	gcc -o Matriz3D ./bin/LDED.o ./bin/main.o

LDED.o: LDED.c
	gcc -o ./bin/LDED.o -c LDED.c

main.o: main.c
	gcc -o ./bin/main.o -c main.c

clear:
	rm ./bin/*.o *.exe

run: Matriz3D
	./Matriz3D
