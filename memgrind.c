#include <stdlib.h>
#include <stdio.h>
#include "mymalloc.h"
#include <stddef.h>
#include <time.h>

void JobA();
void JobB();
void JobC();
void JobD();
void JobE();
void JobF();

/*
int main
{
return 0;
}
*/ 

/*
float workload_time()
{
	clock_t start = clock(), diff;
	//Call Job
	diff = clock() - start;
	
	int msec = diff * 1000 / CLOCKS_PER_SEC;	
}
*/ 

//Malloc 150 bytes, and then free them immediately.
void JobA()
{
	char *x;
	int i;

	for(int i = 0; i < 150; i++)
	{	
		x = mymalloc(1);
		myfree(x);
	}
}

//Malloc 150 bytes in 50 byte chunks, and then free them.
void JobB()
{
	char *array;
	//char *x[150];
	int a;
	int b;
	int j;

	for(j = 0; j < 2; j++)
	{
		for(int a = 0; a < 50; a++)
		{
			array[a] = (char*)mymalloc(sizeof(char));
		}
		for(int b = 0; b < 50; b++)
		{
			myfree(array[b]);
		}
	}
}
	
void JobC()
{
	char* array[50]
	int mymallocs; //# of mymallocs
	int frees; //# of myfrees
	int i;
	int r = rand();

	if(frees == 50) //If we've freed 50 times, we've malloc'd enough times. End.
	{
		return; // /Recall JobC??? !!!
	} 

	else if(mymallocs == 50)// We have successfully allocated 50 times, and we have to free more.
	{
		frees++;
		myfree(array[i-1];
		i--;
		return;
	}

	else //else we still NEED to malloc more memory:
	{
		if(frees < mymallocs)
		{
			int r = rand();
			if (r % 2 == 1)
			{
				array[i] = mymalloc(1);
				mymallocs++;
				i++;
				return;
			}
		
			else 
			{
				myfree(array[i-1]);
				frees++;
				i--;
				return;
			}
		}
		else // If more mallocs then free, malloc again.
		{
			array[i] = mymalloc(1);
			i++;
			mymallocs++;
			return;
		}
	}
}

void JobD()
{	
	//int max_size = 10; // Not needed?
	char* array[50]
	int mymallocs; //# of mymallocs
	int frees; //# of myfrees
	int i;
	int r = rand();

	if(frees == 50) //If we've freed 50 times, we've malloc'd enough times. End.
	{
		return; // /Recall JobD??? !!!
	} 

	else if(mymallocs == 50)// We have successfully allocated 50 times, and we have to free more.
	{
		frees++;
		myfree(array[i-1];
		i--;
		JobD();
	}

	else //else we still NEED to malloc more memory:
	{
		if(frees < mymallocs)//Then we have to EITHER malloc or free again
		{
			if (r % 2 == 1)
			{
				r2 = ((rand() % 64) + 1);
				array[i] = (char*)mymalloc(sizeof(char)*r2;
				mymallocs++;
				i++;
				JobD();
			}
			else 
			{
				myfree(array[i-1]);
				frees++;
				i--;
				JobD();
			}
		}
		else
		{
			r2 = ((rand() % 64) + 1);
			array[i] = (char*)mymalloc(sizeof(char)*r2;
			i++;
			mymallocs++;
			JobD();
		}
	}
}		

void JobE()
{

}		
			
			
	

	
	
	



}
	


















