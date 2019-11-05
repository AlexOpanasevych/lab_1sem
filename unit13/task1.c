/* ----------------------------------------------------------------<Header>-
 Name: task1.c
 Title: miles and kilometers calculator.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2018-12-06
 Description: Задача 13.1. "Расход бензина"
Расход бензина обычно измеряется в милях на один галлон в США и в литрах на 100 километров
в Европе. Ниже приведена часть программы, которая предлагает пользователю выбрать режим
(метрический или американский), а затем выполняет сбор данных и вычисляет расход топлива:
 ------------------------------------------------------------------</Header>-*/
#include <stdio.h>
#include "fuel13-2a.h"
int mode;
int main(void) {
    printf("Enter 0 for metric mode, 1 for US mode: ");
    while (mode >= 0) {
        set_mode();
        get_info();
        show_info();
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");
    return 0;
}
