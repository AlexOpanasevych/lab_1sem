#include <stdio.h>
#include <stdlib.h>
#define SPACE ' '
#define RESULT "results.txt" //defines output file
#define INPUT "input.txt" //defines input file
void intTOchar(int row, int col, int array[row][col], char output[row][col]){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(array[i][j]==0) output[i][j]=SPACE;
            if(array[i][j]==1) output[i][j]='.';
            if(array[i][j]==2) output[i][j]='\'';
            if(array[i][j]==3) output[i][j]=':';
            if(array[i][j]==4) output[i][j]='~';
            if(array[i][j]==5) output[i][j]='*';
            if(array[i][j]==6) output[i][j]='=';
            if(array[i][j]==7) output[i][j]='^';
            if(array[i][j]==8) output[i][j]='%';
            if(array[i][j]==9) output[i][j]='#';

        }
    }
    //output[row][col+1] = '\0';
}
void screen(int row, int col, char array[row][col]){
    FILE *results;
    if((results=fopen(RESULT, "w"))==NULL) printf("Error. File \"%s\" is missing!\n", RESULT);
    else for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%c ", array[i][j]);
            fprintf(results,"%c ", array[i][j]);
        }
        putchar('\n');
        fprintf(results, "\n");
    }
}
int main(void){
    FILE *input;
    int row, col;
    printf("Enter size of a screen (row than col): ");
    scanf("%d %d", &row, &col);
    char output[row][col+1];
    int file_inp[row][col];
    if((input=fopen(INPUT, "r"))==NULL){
        fprintf(stderr, "Error. Cold not open the input file \"%s\".\n", INPUT);
        exit(EXIT_FAILURE);
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            fscanf(input, "%d", &file_inp[i][j]);
        }
    }
    intTOchar(row, col, file_inp, output);
    screen(row, col, output);
    fclose(input);
    return 0;
}
