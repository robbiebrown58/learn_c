all: funclient

funcstatic: 
	gcc -std=c99 -O0 -g funcstatic.c

funclient: funclient.o funcstatic.o
	gcc -std=c99 funclient.o funcstatic.o -o funclient.out

funclient.o: funclient.c
	gcc -std=c99 -O0 -g -c funclient.c

funcstatic.o: funcstatic.c
	gcc -std=c99 -O0 -g -c funcstatic.c

clean:
	rm *.o *~ *.gch *.out