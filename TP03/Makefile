all: Circuits

Circuits: ArvNaoOrd.o main.o
	gcc -o Circuits ArvNaoOrd.o main.o

ArvNaoOrd.o: ArvNaoOrd.c
	gcc -o ArvNaoOrd.o -c ArvNaoOrd.c

main.o: main.c
	gcc -o main.o -c main.c

clear:
	rm *.o *.exe

run: 
	./Circuits
