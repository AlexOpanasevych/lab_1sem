// программа которая сдвигает строку на нное количество единиц

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <cs50.h>
	

void shift(int *x)
{	
    int n;
    int ref = *x;
    char buffer[n]; 
	string get_string(string format, ...);
	printf("Введите число на которое нужно сдвинуть строку :\n");	
	do {
		scanf("%d", &ref);
	}
	while(ref<=-25 || ref>=25);
	printf("Введите фразу которую хотите сдвинуть :\n");
	fgets(buffer, sizeof(buffer), stdin);
	n = strlen(buffer);
	for(int j = 0; j < abs(ref); j++) {
	int temp=buffer[0];
	for(int i = 0; i < n-1; i++) {
		buffer[i]=buffer[i+1]; //смещаем все оставшееся влево
	}
	buffer[n-1] = temp; 
	printf("%s\n", buffer);
	}
}




int main(void) {
	int n;
	shift(&n);
	return 0;
}

