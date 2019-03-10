all: memgrind.c mymalloc.o
	gcc -g memgrind.c  mymalloc.o -o mymalloc
mymalloc.o: mymalloc.c
	gcc -g -c mymalloc.c 
clean:
	rm -rf *o mymalloc
