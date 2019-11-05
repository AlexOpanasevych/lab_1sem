#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "testFunctions.h"

int main(){
    unsigned i, j, k, LinesCount;// 
    char* phrase = (char*)malloc(sizeof(char)*MAX_SIZE);
    stringInput(phrase);
    printf("phrase - %s\n", phrase);
    k = strlen(phrase);
    printf("Enter key: ");
	scanf("%d",&LinesCount);
	getchar();
	unsigned NumbersCount = round((k-1)/LinesCount)+1;// size of col for scitale
	if (NumbersCount < 1) // proverka
	{
		return -1;
	}
	// Print entered size
	printf("Array size: %dx%d\n",LinesCount,NumbersCount);
 
    char** p = (char **)malloc(sizeof(char*)*LinesCount); 
    unsigned counter = 0;
    for (j = 0;  j < LinesCount; j++)
    {
    	p[j] = (char *)malloc(sizeof(char)*NumbersCount);
    	for (i = 0; i < NumbersCount; i++)
    	{
    		p[j][i] = phrase[counter];
    		counter++;
    		printf("%c", p[j][i]);
    	}
    	printf("\n");
    }
    printf("Encripted text:\n");
    for (int f = 0;  f < NumbersCount; f++)
    {
    	for (int d = 0; d < LinesCount; d++)
    	{

    		printf("%c", p[d][f];
    	}
    }
}
