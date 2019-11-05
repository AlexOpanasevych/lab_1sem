/* ----------------------------------------------------------------<Header>-
 Name: task12.2.c
 Title: Task 2 for 12 practice.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2018-11-29
 Revised: _
 Description:   Разработайте функцию str_idx(s, t), которая выдает
  позицию самого правого вхождения t в s или -1, если вхождения не обнаружено.

 ------------------------------------------------------------------</Header>-*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 8

int str_idx(char *s, char *t){
	int ssize = strlen(s), tsize = strlen(t);
	for (int i = tsize - 1; i > 0; i--){
		for (int j = 0; j < ssize; j++){
			if(t[i] == s[j]) {return j+1;}
			else {return -1;}
		}
	}
	return 0;
}

int main(void) {
	printf("Enter a size of array:\n");
	int size;
	scanf("%d", &size);
	getchar();
	char *s = (char*)malloc(size*sizeof(char));
	char *t = (char*)malloc(size*sizeof(char));
	fgets(s, 256, stdin);
	printf("now Enter another string\n");
	fgets(t, 256, stdin);
	if (str_idx(s, t) == -1){printf("string t does not exist in s\n");}
	else printf("%d", str_idx(s, t));
	return 0;
}