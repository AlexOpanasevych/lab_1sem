#include <stdio.h>
#include <string.h>
#define DSIZE 256

FILE* openFile(char filename[],char mode[]){
    FILE* fHandle;
    if((fHandle = fopen(filename,mode)) == NULL){
        fprintf(stderr,"\nError opening file %s",filename);
        return NULL;
    }
    return fHandle;
}

void outFile(FILE* fHandle){
    char temp[256];
    while(fscanf(fHandle,"%s",temp) != -1){
        if(temp == NULL){
            break;
        }
        printf("%s",temp);        
    }
}

int main(int argc, char* argv[]){

    for(int i = 1; i < argc; i++){
        FILE* fHandle = openFile(argv[i],"r");
        if(fHandle != NULL){
            outFile(fHandle);
        }
    }
    return 0;
}