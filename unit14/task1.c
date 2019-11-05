#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

int main() {
	int ch;
	char filename[50];
	FILE *fp;
	unsigned long count = 0;
	printf("Enter filename: ");
	scanf ("%s", filename);
	if ((fp = fopen(filename, "r")) == NULL) {
		printf("Can`t open %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF) {
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("File %s has %lu characters\n", filename, count);
	return 0;
}