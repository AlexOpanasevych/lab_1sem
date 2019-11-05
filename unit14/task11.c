/* ----------------------------------------------------------------<Header>-
 Name: task11.c
 Title: StringFinder
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2018-12-13
 Description: Разработайте программу, которая принимает два аргумента командной строки. Первый аргумент
- это строка, а второй - имя файла. Программа должна искать в файле и выводить все строки,
содержащие указанную. Используйте функцию fgets(). Для поиска строки, содержащей заданную,
применяйте функцию strstr()из стандартной библиотеки С.
 ------------------------------------------------------------------</Header>-*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 256

void read(FILE *fp, char * strin){
    char *stringArray = (char*)malloc(MAX_BUFFER*sizeof(char));
    while(fgets(stringArray, MAX_BUFFER, fp) != NULL){
        if (strstr(stringArray, strin) != NULL){
            puts(stringArray);
        }
    }
}

int main(int argc, char **argv){
    FILE *fp;
    if(argc != 3) {
        printf("usage: %s <string> <filename>", argv[0]);
        return -1;
    }
    if((fp = fopen(argv[2], "r")) == NULL){
        return -1;
    }
    read(fp, argv[1]);
    return 0;
}