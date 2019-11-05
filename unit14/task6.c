/* ----------------------------------------------------------------<Header>-
 Name: task6.c
 Title: PromptForInputFile
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2018-12-14
 Description: Программы, работающие с аргументами командной строки, полагаются на то, что пользователь
помнит, как их правильно запускать. Модифицируйте программу так, чтобы вместо использования
аргументов командной строки она предлагала пользователю ввести необходимую информацию:
 Output: 
PS C:\cygwin64\home\Саня\unit14> ./a
Input size of file name:
11
Input arguments like this: file.txt
detrov.txt
done
 ----------------------------------------------------------------<Header>-*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 80
int main(){
    FILE *in,*out;
    int ch;
    int size;
    printf("Input size of file name:\n");
    scanf("%d", &size);
    getchar();
    char ArgArray[size];
    printf("Input arguments like this: file.txt\n");
    fgets(ArgArray, size, stdin);
    char name[LEN+1];
    int count=0;
    if((in=fopen(ArgArray,"r"))==NULL){
        fprintf(stderr,"I couldn't open the file \"%s\"\n", ArgArray);
        exit(EXIT_FAILURE);
    }
    strncpy(name, ArgArray, LEN-5);
    name[LEN-5]='\0';
    strcat(name,".red");
    //printf("done\n");
    if((out=fopen(name,"w"))==NULL){
        fprintf(stderr,"Can't create output file.\n");
        exit(3);
    }
    //printf("done\n");
    //ch = fseek(in, 0L, SEEK_SET);
    while((ch=getc(in))!=EOF){
        if(count++ %3 == 0){
            putc(ch,out);
            //printf("done\n");
        }
    }
    //printf("done\n");
    if(fclose(in)!=0||fclose(out)!=0)
        fprintf(stderr,"Error in closing files\n");
    //printf("done\n");
    return 0;
}