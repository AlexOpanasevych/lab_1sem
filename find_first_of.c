#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

int str_idx(char *s, char *t){
	int result = -1;
	for (int i = 0; s[i] != '\0' && s[i] != '\n'; i++){
		for (int j = 0; t[j] != '\0' && t[j] != '\n'  && s[i+j] == t[j]; j++){
			if (t[j] == '\0' || t[j] == '\n') {
				result = i;
			}
		}
	}
	return result;
}

int main(void) {
	printf("Enter a size of array:\n");
	int size;
	scanf("%d", &size);
	getchar();
	char *s = (char*)malloc(size*sizeof(char));
	char *t = (char*)malloc(size*sizeof(char));
	printf("Enter first string:\n");
	fgets(s, 256, stdin);
	printf("now Enter another string\n");
	fgets(t, 256, stdin);
	int result = str_idx(s, t);
	if (result == -1){printf("string t does not exist in s\n");}
	else printf("Last occurence of searched string is on position %d", result);
	return 0;
}