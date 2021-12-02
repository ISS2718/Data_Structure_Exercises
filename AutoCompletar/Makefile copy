all: AutoComlete

AutoComlete: LDED.o main.o
	gcc -o AutoComlete LDED.o main.o

LDED.o: LDED.c
	gcc -o LDED.o -c LDED.c

main.o: main.c
	gcc -o main.o -c main.c

clear:
	rm *.o *.exe

run: 
	./AutoComlete
