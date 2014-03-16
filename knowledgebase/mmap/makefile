all: zerobacked anonbacked filebacked_read filebacked_write

zerobacked: zerobacked.c
	gcc -std=gnu99 -g zerobacked.c -o zerobacked.out

anonbacked: anonbacked.c
	gcc -std=gnu99 -g anonbacked.c -o anonbacked.out

filebacked_read: filebacked_read.c
	gcc -std=gnu99 -g filebacked_read.c -o fileread.out

filebacked_write: filebacked_write.c
	gcc -std=gnu99 -g filebacked_write.c -o filewrite.out

clean:
	rm *.out *~
