/* ----------------------------------------------------------------<Header>-
 Name: task3.c
 Title: Counter
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2018-12-06
 Description: "Counter"
Напишите и протестируйте в цикле функцию, которая возвращает количество ее вызовов.
 ------------------------------------------------------------------</Header>-*/
#include <stdio.h>

int counter = 0;

void function(){
    counter++;
}

int main(){
    printf("\npress 'enter' to function ('q' to exit)\n");
    do{
        getchar(); // skipping the \n
        function(); //call a function
    } while(getchar() != 'q');
    printf("\nNumber of calls: %d",counter);
    return 0;
}