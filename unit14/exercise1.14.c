#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void preobrazovanie(char *arguments, float *massiv){
    for(int i = 0, n = sizeof(arguments); i<n; i++){
        if(arguments[i]>='0' && arguments[i]<='9'){
            massiv[i] = atoi(arguments[i]);
        }
    }
}

float discriminant(float *massiv){
    int discr = massiv[1]*massiv[1]-4*massiv[0]*massiv[2];
    if(discr < 0){
        return -1;
    }
    return discr;
}

int main(int argc, char **argv) {
    if(argc > 4 && argc < 4){
        printf("Usage: ./name arg1 arg2 arg3\n");
    }
    char arguments[argc];
    for(int i = 0; i<argc-1; i++){
        arguments[i]=argv[i+1];
        printf("%c", arguments[i]);
    }
    float massiv[argc-1];
    preobrazovanie(arguments, massiv);
    float discr = discriminant(massiv);
    float x1 = (-1*massiv[1]-sqrt(discr))/2*massiv[0];
    float x2 = (-1*massiv[1]-sqrt(discr))/2*massiv[0];
    printf("x1 = %f, x2 = %f", x1, x2);
}