// recursive function to check if number is simple

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int simpleNumber(int number) {
	int i = 2; 
    if (i < (number/2) + 1) {
        if (number % i == 0)
    	{
        	return false;
    	}
    	else {
        	return simpleNumber((number/2)/i+1);
    	}
    }
    return 0;
}

int main() {	

	int number;
	scanf("%d", &number);
	simpleNumber(number);
	if(true) {
		printf("simple");
	}
	else {
		printf("not simple");
	}
	return 0;
}