#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	int chO ,chC;
	FILE *original , *copy;
	if (argc != 3) {
		printf("Please enter only 2 filenames");
		exit(EXIT_FAILURE);
	}
	if ((original = fopen(argv[1],"rb")) == NULL) {
		printf("Open failure%s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((copy = fopen(argv[2],"wb+")) == NULL) {
		printf("Open failure %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	printf("\nFile \"%s\"\n", argv[1]);
	while ((chO = getc(original)) != EOF) {
		putc(chO, stdout);
		putc(chO, copy);
	}
	fclose(copy);
	printf("File \"%s\"\n",argv[2]);
	if ((copy = fopen(argv[2],"rb")) == NULL) {
		printf("Open failure%s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	while ((chC = getc(copy)) != EOF) {
		putc(chC, stdout);
	}
	fclose(original);
	return 0;
}