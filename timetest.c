#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int i;

float start;
float end;
//float time;

void WorkloadA();
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

/*	//Perform WorkloadB
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
/*
	//clock() method prints big pos or negative integer
	startA = clock();
	JobA();
	endA = clock();
	timeA += (endA - startA)/(double)(CLOCKS_PER_SEC);;

	clock_t startB = clock();
	JobB();
	clock_t endB = clock();
	timeB += ((double)(endB - startB) / CLOCKS_PER_SEC);

	clock_t startC = clock();
	JobC();
	clock_t endC = clock();
	timeC += ((double)(endC - startC) / CLOCKS_PER_SEC);

	clock_t startD = clock();
	JobD();
	clock_t endD = clock();
	timeD += ((double)(endD - startD) / CLOCKS_PER_SEC);

	clock_t startE = clock();
	JobE();
	clock_t endE = clock();
	timeE += ((double)(endE - startE) / CLOCKS_PER_SEC);

	clock_t startF = clock();
	JobF();
	clock_t endF = clock();
	timeF += ((double)(endF - startF) / CLOCKS_PER_SEC);}
*/


	}



timeA = timeA/100;
/*
timeB = timeB/100;
timeC = timeC/100;
timeD = timeD/100;
timeE = timeE/100;
timeF = timeF/100;
*/
printf("Workload A took: %d microseconds\n", timeA);
/*
printf("Workload B took: %d microseconds\n", timeB);
printf("Workload C took: %d microseconds\n", timeC);
printf("Workload D took: %d microseconds\n", timeD);
printf("Workload E took: %d microseconds\n", timeE);
printf("Workload F took: %d microseconds\n", timeF);
*/

return 0;

}

void WorkloadA()
{
	for(i = 0; i < 10000; i++)
	{
	}



}





















