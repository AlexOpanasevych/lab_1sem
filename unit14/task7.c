#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256

char file_1[SIZE/2] = "\0";
char file_2[SIZE/2] = "\0";
void fileprint(FILE *file1,FILE *file2){
    int counter=1;
    char ch, cs;
    printf("File: <%s>                          <%s>\n", file_1, file_2);
    printf("%d. \n",counter);
    while((ch=fgetc(file1))!=EOF){
        if(ch=='\n'){
            printf("                         ");
            while((cs=fgetc(file2))!=EOF){
                putchar(cs);
                if(cs=='\n') break;
            }
            counter++;
            printf("%d. ",counter);
        }
            putchar(ch);
    }
    putchar('\n');
}
int main(int argc, char *argv[]){
    if(argc==3){
        strcpy(file_1, argv[1]);
        strcpy(file_2, argv[2]);
        //printf("Strings: %s %s", file_1, file_2);
    }else if(argc>3 || argc==2){
        printf("Usage: <%s> <filename> <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }else{
        char usr_input[SIZE];
        printf("Enter names of files: ");
        fgets(usr_input, SIZE, stdin);
        int i=0;
        while(usr_input[i]!=' '){
            file_1[i]=usr_input[i];
            i++;
        }
        int j=0;
        while(i<strlen(usr_input)){
            file_2[j]=usr_input[i];
            i++;
            j++;
        }
        //printf("%s %s", file_1, file_2);
    }
    FILE *file1, *file2;
    if((file1=fopen(file_1, "r"))==NULL){
        fprintf(stderr, "Error in opening <%s> file", file_1);
        exit(EXIT_FAILURE);
    }
    if((file2=fopen(file_2, "r"))==NULL){
        fprintf(stderr, "Error in opening <%s> file", file_2);
        exit(EXIT_FAILURE);
    }
    fileprint(file1, file2);
    fclose(file1);
    fclose(file2);
    return 0;
}
/*Results:
File: <file1.txt>                          <file2.txt>
1.
Hello world of C!                         Hello world of C!
2.
I am a very 'good' programmer.                         Lorem ipsum dolor set amit...
3.
//JavaScript version 5.1 2013(c)//
*/
