CC=gcc
CFLAGS=-Wall -Werror

all : tour_infirmiere
	
tour_infirmiere : tour_infirmiere.o fcts_kruskal.o
	$(CC) $(CFLAGS) tour_infirmiere.o fcts_kruskal.o -o tour_infirmiere

tour_infirmiere.o : tour_infirmiere.c tour_infirmiere.h fcts_kruskal.h
	$(CC) $(CFLAGS) -c tour_infirmiere.c

fcts_kruskal.o : fcts_kruskal.c fcts_kruskal.h
	$(CC) $(CFLAGS) -c fcts_kruskal.c
	
clean :
	rm -rf *~ *.o

mrproper :
	make clean
	rm tour_infirmiere