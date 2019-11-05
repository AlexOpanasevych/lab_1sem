/* ----------------------------------------------------------------<Header>-
 Name: task2.c
 Title: printWords
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2018-12-20
 Description: 
 Output:
PS C:\cygwin64\home\Саня\unit15> ./a
How many words do you wish to enter? 6
Enter 6 words now:
I love my family so much
Here are your words:
I
love
my
family
so
much
 ------------------------------------------------------------------</Header>-*/
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include <string.h>
#define BUFFER_SIZE 32
int main(void){
    int size;
    printf("How many words do you wish to enter? ");
    scanf("%d", &size);
    char **get_pointer;
    if((get_pointer = (char**)malloc(size*sizeof(char)))==NULL){
        fprintf(stderr, "Error. Memory allocation failed: FILE: %s, LINE: %d, FUNC: %s", __FILE__, __LINE__, __func__);
    }
    printf("Enter %d words now:\n", size);
    char *tmp;
    for(int i = 0; i < size; i++){
        if((tmp = (char*)malloc(BUFFER_SIZE*sizeof(char)))==NULL){
            fprintf(stderr, "Error. Memory allocation failed: FILE: %s, LINE: %d, FUNC: %s", __FILE__, __LINE__, __func__);
        }
        if(!scanf("%s", tmp)){
            fprintf(stderr, "Error. SCANF failed: FILE: %s, LINE: %d, FUNC: %s", __FILE__, __LINE__, __func__);
        }
        //printf("DEBUG: tmp=\"%s\"\n",tmp);
        if(i == 0) printf("Here are your words: \n");
        get_pointer[i] = tmp;
        //printf("DEBUG: get_pointer[%d]=\"%s\"\n",i,get_pointer[i]);
        printf("%s\n", get_pointer[i]);
    }
    return 0;
}
