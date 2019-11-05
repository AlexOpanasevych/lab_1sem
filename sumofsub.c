#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#define SIZE 1000000


const int MININT = INT_MIN;


int sumofsub1(int vector[], int size) {
	int maxsofar = MININT;
	int maxendinghere = 0;
	for (int index = 0; index < size; index++)
	{
		maxendinghere = (maxendinghere + vector[index] > 0) ? maxendinghere + vector[index] : 0;
		maxsofar = (maxendinghere > maxsofar) ? maxendinghere : maxsofar;
	}
	return maxsofar;
}

int main(void)
{
	int data[SIZE];
	for(int i = 0; i<SIZE; i++){
		data[i]	= rand() % 100;
	}
	clock_t before = clock();
	printf("Max sumofsub of data = %d\n", sumofsub1(data, SIZE));
	clock_t difference = clock() - before;
	int msec = difference*1000/CLOCKS_PER_SEC;
	printf("Time taken - %d milisec\n", msec);
	return 0;
}