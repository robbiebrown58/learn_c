all: console

#Interactive test

console: console.c
	gcc -std=c99 console.c -o console.out

#Linked List
llclient: linkedlist.o llclient.o
	gcc -std=c99  llclient.o linkedlist.o -o llclient.out

llclient.o: llclient.c
	gcc -std=c99 -O0 -c -g llclient.c

linkedlist.o: linkedlist.c
	gcc -std=c99 -O0 -c -g linkedlist.c

#Stack
sclient: sclient.o stack.o linkedlist.o
	gcc -std=c99 sclient.o stack.o linkedlist.o -o sclient.out

sclient.o: sclient.c
	gcc -std=c99 -O0 -c -g sclient.c

stack.o: stack.c
	gcc -std=c99 -O0 -c -g stack.c

#Queue


#clean
clean:
	rm *.o *~ *.gch *.out
