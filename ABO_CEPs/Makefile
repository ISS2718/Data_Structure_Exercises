all: ABO_CEPs

ABO_CEPs: ArvoreAVL.o main.o
	gcc -o ABO_CEPs ArvoreAVL.o main.o

ArvoreAVL.o: ArvoreAVL.c
	gcc -o ArvoreAVL.o -c ArvoreAVL.c

main.o: main.c
	gcc -o main.o -c main.c

clear:
	rm *.o *.exe

run: 
	./ABO_CEPs
