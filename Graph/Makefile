
ADT_LLIST.o: ADT_LLIST.c ADT_LLIST.h  

	gcc -c ADT_LLIST.c

ADT_GRAPH.o: ADT_GRAPH.c ADT_GRAPH.h
	
	gcc -c ADT_GRAPH.c

main.o : main.c

	gcc -c main.c


all : ADT_GRAPH.o ADT_LLIST.o main.o

	gcc -o GRAPH ADT_GRAPH.o ADT_LLIST.o main.o
