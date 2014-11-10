CC=gcc
CFLAGS=-Wall -Werror

all : kruskal

kruskal : kruskal.o fcts_kruskal.o
	$(CC) $(CFLAGS) kruskal.o fcts_kruskal.o -o kruskal 

kruskal.o : kruskal.c fcts_kruskal.h kruskal.h
	$(CC) $(CFLAGS) -c kruskal.c
	
fcts_kruskal.o : fcts_kruskal.c kruskal.h
	$(CC) $(CFLAGS) -c fcts_kruskal.c
	
clean :
	rm -rf *~ *.o kruskal
