#ifndef _MY_MALLOC_H
#define _MY_MALLOC_H
#include <stdio.h>
#include <stddef.h>

#define malloc(x) mymalloc(x)
#define free(x)   myfree(x)

static char memoryBlock[4096];
void *mymalloc(size_t resquestedSize);
void myfree(void * memory);
void nodeCreator();
void combineFreeSpace();
#endif
