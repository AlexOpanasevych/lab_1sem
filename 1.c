// програма, що заповнює массив по спіралі
#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main(void)
{
	int n;
    int	sum = 1, j, k;
	do {
	printf("Input size of matrix :\n");
	scanf("%d", &n);
	} while(n < 0 || isalpha(n));
	int A[n][n];
	int p = ceil((double)n/2);
	for(k = 0; k < p; k++)/*loop*/
    {
		for (j = k; j <= n-1-k; j++) {
			A[k][j]=sum++;
		}
		for (j = k+1; j <= n-1-k; j++) {
			A[j][n-1-k]=sum++;
        }
		for (j = n-2-k;j >= k;j--) {
			A[n-k-1][j] = sum++;
		}
		for (j=n-2-k; j > k; j--) {
			A[j][k] = sum++;
		}
	}
	for(int i = 0;i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("%d\t", A[i][j]);
		}
		printf("\n");
	}
	return 0;
}