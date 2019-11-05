/* ----------------------------------------------------------------<Header>-
 Name: task8.c
 Title: SymbolFinder
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2018-12-13
 Description: Разработайте программу, которая принимает в качестве аргументов командной строки символ и
ноль или более имен файлов. Если за символом не следуют аргументы, программа должна читать
стандартный ввод. В противном случае она должна открывать каждый файл по очереди и
сообщать, сколько раз в нем встречается указанный символ. Вместе с результатом каждого
подсчета должны быть указаны имя файла и сам символ. Предусмотрите средства проверки
ошибок, позволяющие выяснить корректность количества аргументов и возможность открытия
файлов. Если файл не может быть открыт, программа должна сообщать об этом факте и
переходить к обработке следующего файла.
 ------------------------------------------------------------------</Header>-*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_MAX 256

int parser(char *inpt, char ch){
    int count = 0;
    for(int i=0; i<strlen(inpt); i++){
        if(inpt[i]==ch){
            count++;
        }
    }
    return count;
}

int main(int argc, char *argv[]){
    char ch = *argv[1];
    if(argc==2){
        char user_input[SIZE_MAX];
        printf("Enter a string:\n");
        fgets(user_input, SIZE_MAX, stdin);
        printf("Your string has %d '%c' characters", parser(user_input, ch), ch);
    }else if(argc>2){
        for(int i=2; i<argc; i++){
            FILE *fp;
            char file_inpt[SIZE_MAX];
            if((fp=fopen(argv[i], "r")) == NULL){
                fprintf(stderr,"Error. Could not open the file \"%s\"\n", argv[i]);
                exit(EXIT_FAILURE);
            }
            fgets(file_inpt, SIZE_MAX, fp);
            printf("File \"%s\" have %d '%c' characters\n", argv[i], parser(file_inpt,ch), ch);
            fclose(fp);
        }
    }else{
        printf("Usage: %s character ||\n %s character filenames", argv[0], argv[0]);
    }
    return 0;
}
