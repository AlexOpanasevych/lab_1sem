/* ----------------------------------------------------------------<Header>-
 Name: task2.c
 Title: miles and kilometers calculator(remake).
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2018-12-06
 Description:  "Remake"
Переделайте программу, описанную в Задаче 13.1, чтобы в ней использовались только
автоматические переменные. Обеспечьте в программе тот же самый пользовательский интерфейс,
т.е. она должна предлагать пользователю ввести режим и т.д. У вас будет другой набор 
вызовов функций!
 ------------------------------------------------------------------</Header>-*/
#include "fuel13-2b.h"
int main(void) {
    int mode;
    printf("Enter 0 for metric mode, 1 for US mode: ");
    while (mode >= 0) {
        float distance, fuel;
        get_info(distance, fuel, mode);
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");
    return 0;
}
/* Output: 
Enter 0 for metric mode, 1 for US mode: 0
Enter distance traveled in kilometers:
600

Enter fuel consumed in liters: 78.8

Fuel consumption is 13.13 liters per 100 km
Enter 0 for metric mode, 1 for US mode (-1 to quit): 1
1
Enter distance traveled in miles:
1

Enter fuel consumed in gallons:2

Fuel consumption is 0.50 miles per gallon
Enter 0 for metric mode, 1 for US mode (-1 to quit): -1
Done.
*/