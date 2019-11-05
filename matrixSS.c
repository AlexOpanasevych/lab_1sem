/* дан массив целих чисел расмотреть отрезки массива групи нечетних чисел ыбрать наибольшую длину*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SIZE 10

int arrayAnalyzer(int *mass, unsigned n);


int main()
{
	int n;
    int *mass;
    int i;
    printf("give me an array size\n");
    scanf("%d",&n);
 
    mass = (int*)malloc(n*sizeof(int));
 
    srand(time(NULL));
 
    for(i = 0; i < n; i++)
        mass[i] = rand() % 50;
 
    for(i = 0; i < n; i++)
        printf("%d\t", mass[i]);
 
    printf("\n");
 	arrayAnalyzer(mass, n);
    free(mass);
	
	
	return 0;
}

int arrayAnalyzer(int *mass, unsigned n) {
	int counter = 0;
	for(unsigned i = 0; i < n; i++) {
		if(mass[i] % 2 == 1) {
			counter++;
			mass[i] = array[counter];
		}
		else {
			for (unsigned i = 0; i < n; i++)
			{
				printf("%d", array[i]);
			}
			printf("%d\n", counter);
			counter = 0;
		}
	}
	return 0;
}