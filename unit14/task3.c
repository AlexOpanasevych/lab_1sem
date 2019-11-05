#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ARG 2
#define MAX_LEN 80

int main(void) {
    FILE *in,*out;
    int size;
    printf("Input size of file name:\n");
    scanf("%d", &size);
    getchar();
    char ArgArray[ARG][size];
    printf("Input arguments like this: file.txt\n");
    fgets(ArgArray[0], size, stdin);
    fgets(ArgArray[1], size, stdin);
    if((in=fopen(ArgArray[0],"r"))==NULL){
        fprintf(stderr,"I couldn't open the file \"%s\"\n", ArgArray);
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < MAX_LEN; i++){
        toupper(ArgArray[1][i]);
    }
    strncpy(ArgArray[1], ArgArray[0], MAX_LEN-5);
    ArgArray[1][MAX_LEN-5]='\0';
    strcat(ArgArray[1],".txt");
    //printf("done\n");
    if((out=fopen(ArgArray[1],"w"))==NULL){
        fprintf(stderr,"Can't create output file.\n");
        exit(3);
    }
    return 0;
}
