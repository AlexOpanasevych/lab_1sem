/* ----------------------------------------------------------------<Header>-
 Name: task9.c
 Title: task8modify
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2018-12-13
 Description: Модифицируйте программу, чтобы каждое слово было пронумеровано в соответствии с порядком
его добавления в список, начиная с 1. Позаботьтесь о том, чтобы при втором запуске
программы новая нумерация слов начиналась с того места, где была закончена нумерация при
предыдущем запуске.
Output: PS C:\cygwin64\home\Саня\unit14> ./a
Enter words to add to the file; press the #
key at the beginning of a line to terminate
i love my family
#
File consist of
1. i
2. love
3. my
4. family
Done
 ------------------------------------------------------------------</Header>-*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 40

int main(void) {
	FILE *fp;
	int nmbr = 1;
	char wrds[MAX+1];
	if ((fp = fopen("wordy", "a+")) == NULL) {
		fprintf(stdout, "Can`t open \"wordy\" file.\n");
		exit(EXIT_FAILURE);
	}
	puts("Enter words to add to the file; press the #\nkey at the beginning of a line to terminate");
	while (fscanf(stdin, "%40s", wrds) == 1 && (wrds[0] != '#')) {
		fprintf(fp, "%s\n", wrds);
	}	
	puts("File consist of");
	rewind(fp);
	while (fscanf(fp, "%s", wrds) == 1) {
		nmbr += 1;
		printf ("%d. ", nmbr-1);
		puts(wrds);
	}
	puts("Done");
	if (fclose(fp) != 0) {
		fprintf(stderr, "Error! Closing file\n");
	}
	return 0;
}