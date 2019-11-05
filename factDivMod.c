#include <locale.h>
#include <stdio.h>
#include <math.h>
#define MAX 10000000
typedef long long in;

in fact(in no, in M){
	in i, f = 1;
	for(i=1; i<= no; i++){
		f = (f*i)%M;
		if(f==0) break;
	}
	return f;
}

int max(int a, int b) {
	return (a<b) ? b : a;
}
 
int find(int M){
	int low = 1, high = MAX, mid, ans = low;
	while(low <= high){
		mid = (low + high)/2;
		if(fact(mid, M)==0){
			ans = mid;
			high = mid - 1;
		}else{ 
			low = mid + 1;
		}
	}
	return ans;
}
 
int main() {
	int a, b;
	setlocale(LC_ALL, "ru_RU");
	printf("Введіть числа :\n");
	while(scanf("%d %d", &a, &b) != EOF){
		if(max(0, find(b)-find(a)) != 0){
		printf("Факторіал %d! ділиться націло на %d\n", a, b);
		}
		else printf("Факторіал %d! не ділиться націло на %d\n", a, b);
	}
	return 0;
}