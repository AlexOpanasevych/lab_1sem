/* ----------------------------------------------------------------<Header>-
 Name: task13.c
 Title: task12modify
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2018-12-13
 Description: Выполните Задачу 14.12, используя массивы переменной длины вместо стандартных массивов.
 Output:
 input a size of array, just like this: 25 50
20 30
    #                   * % # # % * '
        #               * % # # % * * '
                        * % . # % * ~ * '
        #               * % # # % *   ~ * '
    #                   * % # # % *     ~ * '
                        * % # . % *       ~ * '
                        * % # # % *         ~ * '
* * * * * * * * * * * * * % # # % * * * * * * * * * * * * *
% % % % % % % % % % % % * % # # % * % % % % % % % % % % % %
# # # #   # # # # # # # # # # # # # # # # # : # # # # # # #
% % % % % % % % % % % % * % # # % * % % % % % % % % % % % %
* * * * * * * * * * * * * % # # % * * * * * * * * * * * * *
                        * % # # % *
                        * % # # % *         = =
        ' '             * % # # % *     * =     = *
        : :             * % # # % *   * = . . . . = *
        ~ ~             * % # # % *     * =     = *
        * *             * % # # % *         = =
                        * % # # % *
                        * % # # % *
 ------------------------------------------------------------------</Header>-*/
#include <stdio.h>
#include <stdlib.h>
#define SPACE ' '


void intTOchar(int **array, int width, int height, char **output){
//    printf("%d %d %d %d", array[50][65], width, height, output[1][2]);
//	printf("%d %d\n", width, height);
    for(int i=0; i < width; i++){
        for(int j=0; j < height; j++){
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

//	printf("%c ", output[i][j]);
        }
//	printf("\n");
    }
    //output[width][height+1] = '\0';
    //printf("done irc\n");
}
void screen(char **array, int width, int height){
//	printf("SCREEN %d %d\n", width, height);
    FILE *results;
    if((results=fopen("results.txt", "w+"))==NULL){
        printf("Error. File ");
    }
    for(int i=0; i<width; i++){
        for(int j=0; j<height; j++){
            printf("%c ", array[i][j]);
            fprintf(results, "%c ", array[i][j]);
        }
        fputc('\n', results);
        putchar('\n');
    }
	fclose(results);
}
int main(void){
    FILE *input;
    int width, height;
    printf("input a size of array, just like this: 25 50\n");
    scanf("%d %d", &width, &height);
    getchar();
    char **output = (char**)malloc(width*sizeof(char*));
    for(int i = 0; i < width; i++){
         output[i] = (char*)malloc(height*sizeof(char));
    }
//    printf("done");
    int **file_inp = (int**)malloc(width*sizeof(int*));
    for(int i = 0; i < width; i++){
         file_inp[i] = (int*)malloc(height*sizeof(int));
    }
//    printf("done");
    if((input=fopen("input.txt", "r"))==NULL){
        fprintf(stderr, "Error. Cold not open the file.\n");
        exit(EXIT_FAILURE);
    }
//    printf("done");
    for(int i=0; i<width; i++){
        for(int j=0; j<height; j++){
            fscanf(input, "%d", &file_inp[i][j]);
        }
    }
    //printf("done init\n");
    intTOchar(file_inp, width, height, output);
    //printf("done intTOchar\n");
    screen(output, width, height);
    //printf("done screen\n");
    fclose(input);
    //printf("done");
    free(input);
    //printf("done");
    free(file_inp);
    return 0;
}
