#include <stdio.h>
#define MAX 100

int generate(int A, int B){
	int counter = A;
	for (int i = A; i > B; --i) {
		A = i;
		printf("%d %d %d\n", B, A, counter);
		counter = 0;
		while(A!=1) {
			if(A%2==0) A = A/2;
			else A = 3*A+1;
			counter++;
		}
	}
	return 0;
}

int main(void) {
	int a = 100;
	int b = 1;
	generate(a, b);
	return 0;
}