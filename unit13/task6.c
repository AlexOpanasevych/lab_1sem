/* ----------------------------------------------------------------<Header>-
 Name: task6.c
 Title: "Телефонная компания".
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2018-12-06
 Description: 
Компания желает продемонстрировать, что она в состоянии предоставить клиентам
высокоскоростную широкополосную сеть. Для рекламных целей им достаточно создать только одну
такую линию, соединяющую напрямую двух абонентов. Так как стоимость установки такой сети
пропорциональна расстоянию между абонентами, им необходимо узнать, какие два абонента
находятся на минимальном расстоянии, чтобы на эту рекламную затею понадобилось меньше
денег. Иными словами, для заданного множества точек на плоскости найдите расстояние между
двумя ближайшими при условии, что это расстояние должно быть меньше заданного (задать
самостоятельно) порогового значения. Если ближайшие точки находятся на слишком большом
расстоянии, отделу рекламы придется выбирать менее накладную рекламную стратегию. 
 ------------------------------------------------------------------</Header>-*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "functions.h"

#define STR_LEN 256
#define INFINITE 10000


#define SETS_COUNT 2
char* const sets[] = {
    "(0 0) (10000 10000) (20000 20000)",
    "(0 2) (6 67) (43 71) (39 107) (189 140)"
};

int setslengths[] = {3, 5};


int char_to_numb(char symb){
    switch(symb){
        case '1':
            return 1;
            break;
        case '2':
            return 2;
            break;
        case '3':
            return 3;
            break;
        case '4':
            return 4;
            break;
        case '5':
            return 5;
            break;
        case '6':
            return 6;
            break;
        case '7':
            return 7;
            break;
        case '8':
            return 8;
            break;
        case '9':
            return 9;
            break;
        case '0':
            return 0;
            break;
    }
    return 0;
}

int str_to_numb(char* strin, int length){
    int temp = 0;
    for(int i=0; i<length; i++){
        temp *= 10;
        temp += char_to_numb(strin[i]);
    }
    return temp;
}


int* read(int dataLength, char strin[]){
    int* input = malloc(dataLength*sizeof(int));


    int wordsCount = 0; // the counter of words in string
    char token[STR_LEN];
    while(nextToken(strin, dataLength*sizeof(int), token, STR_LEN) == 0){ // reads the words from string to token while not EOL
        input[wordsCount] = str_to_numb(token, strlen(token));
        wordsCount++; // countiing the words
        if(wordsCount == dataLength){
            return input;
        }
    }
    return input;
}

float calc_dist(int x1, int y1, int x2, int y2){
    return sqrt(pow(x2-x1, 2) + pow(y2-y1,2));
}

float calculate_best_dist(int* cords, int length){
    if(length%2 == 1){
        return -1;
    }
    float min = INFINITE;
    int cordCount = length/2;
    for(int i=0; i<cordCount; i+=2){
        for(int j=0; j<cordCount; j+=2){
            if(i != j){
                if(calc_dist(cords[i],cords[i+1],cords[j],cords[j+1]) < min){
                    min = calc_dist(cords[i],cords[i+1],cords[j],cords[j+1]);
                }
            }
        }
    }
    return min;
}

int main(){
    for(int i = 0; i < SETS_COUNT; i++){
        initParser();
        int* temp = read(setslengths[i]*2, sets[i]);
        float temp1 = calculate_best_dist(temp, setslengths[i]*2);
        if(temp1 < INFINITE){
            printf("\nbest distance = %f",temp1);
        }else{
            printf("\nINFINITY");
        }
    }

}
/* Output :
    INFINITY
    36.2215 
*/