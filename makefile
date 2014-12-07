all: main.o arbre.o liste.o pile.o outils.o
	gcc main.o arbre.o liste.o pile.o outils.o -o ABR

main.o: main.c arbre.h liste.h pile.h outils.h
	gcc -c main.c -o main.o

arbre.o: arbre.c
	gcc -c arbre.c -o arbre.o

liste.o: liste.c
	gcc -c liste.c -o liste.o

pile.o: pile.c
	gcc -c pile.c -o pile.o

outils.o: outils.c
	gcc -c outils.c -o outils.o

clean:
	rm -rf *.o