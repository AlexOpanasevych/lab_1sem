#include <stdio.h>
#include <string.h>
#define SIZE 100

void onlyBigLetters(char input[SIZE]) {
	for (int i=0; i<strlen(input)-1; i++) {
		if (input[i] >= 'A' && input[i] <= 'Z') {
			printf ("%c", input[i]);
		}
		else {
			input[i] += 'A'-'a';
			printf ("%c", input[i]);
		}
	}
}

void onlySmallLetters(char input[SIZE]) {
	for (int i=0; i<strlen(input)-1; i++) {
		if (input[i] >= 'a' && input[i] <= 'z') {
			printf ("%c", input[i]);
		}
		else {
			input[i] -= 'A'-'a';
			printf ("%c", input[i]);
		}
	}
}

int main(int atgc, char *argv[]){
	char input[SIZE];
	memset(input, 0, SIZE);
	fgets(input, SIZE, stdin);
	if (*argv[1] == 'p') {
		printf("%s\n", input);
	}
	if (*argv[1] == 'u') {
		onlyBigLetters(input);
	}
	if (*argv[1] == 'l') {
		onlySmallLetters(input);
	}
	if (*argv[1] != 'p' && *argv[1] != 'u' && *argv[1] != 'l') {
		printf("%s\n", input);
	}
	return 0;
}