#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stddef.h>
#include "mymalloc.h>

int i;

float start;
float end;
//float time;

void workloadA();
void workloadB();
void workloadC();
void workloadD();
void workloadE();
void workloadF();

int main(int argc, char* argv[])
{

unsigned int timeA = 0;
unsigned int timeB = 0;
unsigned int timeC = 0;
unsigned int timeD = 0;
unsigned int timeE = 0;
unsigned int timeF = 0;

//Used for system times in clock ticks or CLOCKS_PER_SEC
/*clock_t startA;
clock_t endA;
*/

struct timeval start;
struct timeval end;
struct timeval time;

gettimeofday(&time, NULL);

//For time in microseconds

suseconds_t systime = time.tv_usec;


for(i = 0; i < 100; i++)
{
	//Perform WorkloadA
	gettimeofday(&start, NULL);
	WorkloadA();
	gettimeofday(&end, NULL);
	timeA += (end.tv_usec - start.tv_usec) * CLOCKS_PER_SEC;

	//Perform WorkloadB
	gettimeofday(&start, NULL);
	WorkloadB();
	gettimeofday(&end, NULL);
	timeB += (end.tv_usec - start.tv_usec) * CLOCKS_PER_SEC;

	//Perform WorkloadC
	gettimeofday(&start, NULL);
	WorkloadC();
	gettimeofday(&end, NULL);
	timeC += (end.tv_usec - start.tv_usec) * CLOCKS_PER_SEC;

	//Perform WorkloadD
	gettimeofday(&start, NULL);
	WorkloadD();
	gettimeofday(&end, NULL);
	timeD += (end.tv_usec - start.tv_usec) * CLOCKS_PER_SEC;
/*
	//Perform WorkloadE
	gettimeofday(&start, NULL);
	WorkloadE();
	gettimeofday(&end, NULL);
	timeE += (end.tv_usec - start.tv_usec) * CLOCKS_PER_SEC;

	//Perform WorkloadF
	gettimeofday(&start, NULL);
	WorkloadF();
	gettimeofday(&end, NULL);
	timeF += (end.tv_usec - start.tv_usec) * CLOCKS_PER_SEC;


*/
	}

timeA = timeA/100;
timeB = timeB/100;
timeC = timeC/100;
timeD = timeD/100;
/*
timeE = timeE/100;
timeF = timeF/100;
*/
printf("Workload A took: %d microseconds\n", timeA);
printf("Workload B took: %d microseconds\n", timeB);
printf("Workload C took: %d microseconds\n", timeC);
printf("Workload D took: %d microseconds\n", timeD);
/*
printf("Workload E took: %d microseconds\n", timeE);
printf("Workload F took: %d microseconds\n", timeF);
*/

return 0;


}


//Malloc 150 bytes, and then free them immediately.
void workloadA()
{
	char *testVar;
	int index;

	for(index = 0; index< 150; index++)
	{	
		testVar = (char*)malloc(sizeof(char));
                if (testVar ==NULL){
                  fprintf(stderr, "Error malloc return null in %s at line %d\n", __FILE__, __LINE__);
                  return;
                }
		free(testVar);
	}
	printf("index %d\n",index);
}

void workloadB()
{
	char *testVar[150];
	int index1;
	int index2;
	int j;

	for(j = 0; j < 3; j++)
	{
		for(index1 = 0; index1 < 50; index1++)
		{
			testVar[index1] = (char*)malloc(sizeof(char));
			if (testVar[index1] ==NULL){
                          fprintf(stderr, "Error malloc return null in %s at line %d\n", __FILE__, __LINE__);
                          return;
                       }
		}
		for(index2 = 0; index2< 50; index2++)
		{
			free(testVar[index2]);
		}
	}
	//printf("index 2 in B %d\n", index2);
}
	
void workloadC()
{
	char* array[50];
	int mymallocs=0; //# of mymallocs
	int frees=0; //# of frees
	int i=0;
	int random= rand();
	int j=0;
	
        
	while (j !=1){
	        random= rand();
	        if (frees == mymallocs && mymallocs <50){
	            array[mymallocs] = malloc(1);
		    mymallocs++;
	        }
	        else if(frees < mymallocs && mymallocs <50){
		  if (random % 2 == 1){
		      array[mymallocs] = malloc(1);
		      mymallocs++;
		  }
		  
		else 
		 {
		   free(array[frees]);
		   frees++;
		  }
		 }
		else if (frees < mymallocs && mymallocs==50){
		   free(array[frees]);
		   frees++;
		}
		
		else 
		j =1;
	  }
	//printf("mallocs in CCC %d\t frees %d\n",mymallocs,frees);
}

void workloadD()
{	
	//int max_size = 10; // Not needed?
	char* array[50];
	int mymallocs=0; //# of mymallocs
	int frees=0; //# of frees
	int i=0;
	int random=0;
	int mallocRand=0;
	
	
	
		while (i !=1){
	        random= rand();
	        if (frees == mymallocs && mymallocs <50){
	            mallocRand = rand()%64+1;
	            array[mymallocs] = (char*)malloc(sizeof (char)*mallocRand);
		    mymallocs++;
	        }
	        else if(frees < mymallocs && mymallocs <50){
		   if (random %2 == 1){
		        mallocRand = rand()%64+1;
		        array[mymallocs] = malloc(sizeof(char)*mallocRand);
		        mymallocs++;
		    }
		  
		  else 
		   {
		     free(array[frees]);
		     frees++;
		   }
		 }
		else if (frees < mymallocs && mymallocs==50){
		   free(array[frees]);
		   frees++;
		}
		
		else 
		i =1;
	  }
	   //printf("mallocs in DDD %d\t frees %d\n",mymallocs,frees);
}		


/*void workloadE(){
   int mallocs=0;
   int memoryAllocated =0;
   int memoryLeft = 4096;
   int random;
   char *testVar[170];
   random = rand()%10+1;
   memoryAllocated = memoryAllocated + random + sizeof(Metadata);
   memoryAllocated =memoryAllocated -random - sizeof (Metadata);
   while (memoryAllocated < memoryLeft){
      testVar[mallocs] = malloc(sizeof(char)*random);
      mallocs = mallocs +1;
      random = rand()%10+1;
      memoryAllocated = memoryAllocated + random + sizeof(Metadata);
      memoryAllocated =memoryAllocated -random - sizeof (Metadata);
   }
   mallocs=mallocs -1;
   while (mallocs >=0){
      free(testVar[mallocs]);
      mallocs = mallocs-1;
   }

 printf("mallocs in EEE %d \n",mallocs);
}

void workloadF(){
  int freedPosition[15];
  char * testVar[15];
  int frees = 0;
  int index;
  int i;
  int random;
  int j;
  int x;
  
  for (index=0; index<5; index++){
      frees = 0;
      for (i=0; i<15; i++)
      freedPosition[i]=0;
 
     for (j=0; j<15; j++){
       testVar[j] = (char*)malloc(sizeof(char));
     }
   
     while (frees < 15){
        random = rand()%15;
        for (x =0 ; x <15;x++){
           if (random = freedPosition[i]);
              x =-1;
              break;
       }
        if (x !=-1){
           free(testVar[random]);
           frees = frees +1;
        }
     }
   }
   printf("mallocs in FFF %d\t frees %d\n",frees);
}
*/

