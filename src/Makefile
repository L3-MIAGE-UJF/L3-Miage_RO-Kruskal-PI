CC=gcc
CFLAGS=-Wall -Werror

all : tour_infirmiere
	
tour_infirmiere : tour_infirmiere.o fcts_kruskal.o graphes.o parcours_profondeur.o
	$(CC) $(CFLAGS) tour_infirmiere.o fcts_kruskal.o graphes.o parcours_profondeur.o -o tour_infirmiere

parcours_profondeur.o : parcours_profondeur.c parcours_profondeur.h
	$(CC) $(CFLAGS) -c parcours_profondeur.c

tour_infirmiere.o : tour_infirmiere.c tour_infirmiere.h fcts_kruskal.h graphes.h
	$(CC) $(CFLAGS) -c tour_infirmiere.c

graphes.o : graphes.c graphes.h
	$(CC) $(CFLAGS) -c graphes.c

fcts_kruskal.o : fcts_kruskal.c fcts_kruskal.h
	$(CC) $(CFLAGS) -c fcts_kruskal.c
	
clean :
	rm -rf *~ *.o

mrproper :
	make clean
	rm tour_infirmiere
