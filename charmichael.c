#include <stdio.h>
#include <stdbool.h>
int gcd(int a, int b) 
{ 
    if (a < b) 
        return gcd(b, a); 
    if (a % b == 0) 
        return b; 
    return gcd(b, a % b); 
} 

bool is_prime(int n) {
    if (n <= 1)
        return true;
    if (n == 2)
        return true;
    if (n%2==0)
        return false;
    for (int j = 3; j * j <= n; j+=2)
         if (n % j == 0) return false;

    return true;
}

int power(int x, int y, int mod) { 
    if (y == 0) 
        return 1; 
    int temp = power(x, y / 2, mod) % mod; 
    temp = (temp * temp) % mod; 
    if (y % 2 == 1) 
        temp = (temp * x) % mod; 
    return temp; 
}

bool isCarmichaelNumber(int n) {
    for (int b = 2; b < n; b++) { 
        // If "b" is relatively prime to n 
        if (gcd(b, n) == 1) {
  
            // And pow(b, n-1)%n is not 1, 
            // return false. 
            if (power(b, n - 1, n) != 1){
                return false; 
            }
        }
    } 
    return true; 
} 

int main()
{
	int number;
	do{
	printf("введите число\n");
	scanf("%d", &number);
	if(isCarmichaelNumber(number) == 1 && !is_prime(number)){
	printf("Number %d is Carmichael Number\n", number);
	}
	else printf("Number %d is normal\n", number);
	}while(number !=0); 
	return 0;
}