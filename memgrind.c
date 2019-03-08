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

int main ()
{
return 0;
}

float workload_time()
{
	clock_t start = clock(), diff;
	//Call Job
	diff = clock() - start;
	
	int msec = diff * 1000 / CLOCKS_PER_SEC;	
}

//Malloc 150 bytes, and then free them immediately.
void JobA()
{
	char *testVar;
	int index;

	for(index = 0; index< 150; index++)
	{	
		testVar = mymalloc(1);
                if (testVar ==NULL){
                  fprintf(stderr, "Error malloc return null in %s at line %d\n", __FILE__, __LINE__);
                  return;
                }
		free(testVar);
	}
}

void JobB()
{
	char *testVar[150];
	int index1;
	int index2;
	int j;

	for(j = 0; j < 2; j++)
	{
		for(index1 = 0; index1 < 50; index1++)
		{
			testVar[index1] = (char*)mymalloc(sizeof(char));
			if (testVar[index1] ==NULL){
                          fprintf(stderr, "Error malloc return null in %s at line %d\n", __FILE__, __LINE__);
                          return;
                       }
		}
		for(index2 = 0; index2< 50; index2++)
		{
			free(array[index2]);
		}
	}
}
	
void JobC()
{
	char* array;
	int mymallocs; //# of mymallocs
	int frees; //# of frees
	int i;
	int r = rand();

	if(frees == 50) //If we've freed 50 times, we've malloc'd enough times. End.
	{
		return; // /Recall JobC??? !!!
	} 

	else if(mymallocs == 50)// We have successfully allocated 50 times, and we have to free more.
	{
		frees++;
		free(array[i-1];
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
				free(array[i-1]);
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
	char* array;
	int mymallocs; //# of mymallocs
	int frees; //# of frees
	int i;
	int r = rand();

	if(frees == 50) //If we've freed 50 times, we've malloc'd enough times. End.
	{
		return; // /Recall JobD??? !!!
	} 

	else if(mymallocs == 50)// We have successfully allocated 50 times, and we have to free more.
	{
		frees++;
		free(array[i-1];
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
				free(array[i-1]);
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
	


















