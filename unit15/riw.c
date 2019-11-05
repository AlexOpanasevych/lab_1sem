#include <stdio.h>
#include <math.h>
#include <stdlib.h>


/*double changeArrayValue(char operator) {
    switch(operator){
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        default: return -1;
    }
}*/

double discr(double a, double b, double c){
    return b*b-4*a*c;
}

int main(int argc, char **argv){   
    //char operator[MAX];// "substract", "multiply", "divide"};
    //printf("Input operation and doubles: ");
    double a = atoi(argv[1]), b = atoi(argv[2]), c = atoi(argv[3]);
    if(a == 0) return -1;
    if(b*b-4*a*c < 0) return -2;
    //scanf("%s %lf %lf", operator, &a, &b);
    /*double result = */
    
    printf("x1 = %lf ", (-1*b - sqrt(discr(a, b, c)))/(2*a));
    printf("x2 = %lf", (-1*b + sqrt(discr(a, b, c)))/(2*a));
    return 0;
}