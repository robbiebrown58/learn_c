all: console

#Interactive test

console: console.o menu.o linkedlist.o stack.o queue.o
	gcc -std=c99 console.o menu.o linkedlist.o stack.o queue.o -o console.out

console.o: console.c
	gcc -std=c99 -O0 -c -g console.c

#Linked List

linkedlist.o: linkedlist.c
	gcc -std=c99 -O0 -c -g linkedlist.c

#Stack

stack.o: stack.c
	gcc -std=c99 -O0 -c -g stack.c

#Queue

queue.o: queue.c
	gcc -std=c99 -O0 -c -g queue.c

#Menu

menu.o: menu.c
	gcc -std=c99 -O0 -c -g menu.c


#clean
clean:
	rm *.o *~ *.gch *.out
