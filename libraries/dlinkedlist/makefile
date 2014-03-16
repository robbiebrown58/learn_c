all: client

client: linkedlist.o client.o
	gcc -std=c99  client.o linkedlist.o -o llclient.out

client.o: client.c
	gcc -std=c99 -O0 -c -g client.c

linkedlist.o: linkedlist.c
	gcc -std=c99 -O0 -c -g linkedlist.c

clean:
	rm *.o *~ *.gch *.out
