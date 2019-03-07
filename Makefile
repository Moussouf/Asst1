all: mymalloc.o memgrind.c 
	gcc memgrind.c mymalloc.c
mymalloc.o: mymalloc.c mymalloc.h
	gcc -g -c  mymalloc.c
clean:
	rm -rf *o mymalloc
