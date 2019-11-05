/* ----------------------------------------------------------------<Header>-
 Name: task10.c
 Title: ShowMeStringFromPosition
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2018-12-13
 Description: Разработайте программу, открывающую текстовый файл, имя которого получается интерактивно.
Организуйте цикл, который предлагает пользователю ввести позицию в файле. Затем программа
должна вывести часть файла, начиная с этой позиции и заканчивая следующим символом новой
строки. Цикл ввода должен завершаться при вводе отрицательного дли нечислового значения.
Output: 
./a

EOF = -1
Input the file name: wordy

Input position to get text from and -1 to end session: 10

family
-1
PS C:\cygwin64\home\Саня\unit14> ./a

EOF = -1
Input the file name: цщквн

Error: Can't reach the file
 ------------------------------------------------------------------</Header>-*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_LENGTH 256

char fileName[BUFFER_LENGTH];

char *readPosition(char* text, int start){ //read position in file
    int index = 0;
    char* buffer = malloc(BUFFER_LENGTH);
    while(text[index+start] != '\0' && text[index+start] != '\n'){
        buffer[index] = text[index+start];
        index++;
    }
    buffer[index] = 0;
    return buffer;
}

char* getFile(FILE* fileHandle){ // get file 
    char* buff = malloc(BUFFER_LENGTH);
    char buffChar = 0;
    int i = 0;
    while(fscanf(fileHandle, "%c", &buffChar) != EOF){
        buff[i++] = buffChar;
    }
    buff[i] = 0;
    return buff;
}

char* getRow(FILE* fileHandle, int startPos){

    char* buffFile = getFile(fileHandle);
    char* buffLine;
    if(fileHandle == NULL){

    }else{
        buffLine = readPosition(buffFile, startPos);
        free(buffFile);
    }
    rewind(fileHandle);
    return buffLine;
}

int main(void){
    printf("\nEOF = %d",EOF);
    printf("\nInput the file name: ");
    scanf("%s",fileName);
    FILE* fileHandle;
    if((fileHandle = fopen(fileName, "r")) == NULL){
        fprintf(stderr, "\nError: Can't reach the file");
        exit(EXIT_FAILURE);
    }
    printf("\nInput position to get text from and -1 to end session: ");
    int requestBuff = -1;
    do{
        scanf("%d",&requestBuff);
        if(requestBuff == -1){
            break;
        }
        char* buffer = getRow(fileHandle,requestBuff);
        printf("\n%s\n", buffer);
        free(buffer);
    }while(requestBuff >= 0);
    if(fclose(fileHandle) != 0){
        fprintf(stderr, "\nError: Error closing file");
    }    
    return 0;
}