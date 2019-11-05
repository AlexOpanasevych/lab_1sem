/* ----------------------------------------------------------------<Header>-
 Name: task1.c
 Title: task1modify
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2018-12-20
 Description: Завершите программу, предоставив определения функций make_array() и show_array (). Функция
make_array() принимает два аргумента. Первый аргумент - это количество элементов в массиве
значений int, а второй аргумент — значение, которое должно быть присвоено каждому элеменгу
массива. Эта функция использует malloc() для создания массива подходящего размера,
присваивает каждому элеменгу заданное значение и возвращает указатель на массив. Функция
show_array() отображает содержимое массива по восемь элементов в строке.
 Output:
PS C:\cygwin64\home\Саня\unit15> ./a
Enter the number of elements: 5
Enter the initialization init_value: 3
3 3 3 3 3
Enter the number of elements (<1 to quit): -1
Done.
 ------------------------------------------------------------------</Header>-*/
#include <stdio.h>
#include <stdlib.h>
int *make_array(int el, int val);
void show_array(const int *array, int n);
int main(void){
    int *pointer;
    int size;
    int init_value;
    printf("Enter the number of elements: ");
    while(scanf("%d", &size) == 1 && size>0){
        printf("Enter the initialization init_value: ");
        scanf("%d", &init_value);
        pointer = make_array(size, init_value);
        if(pointer){
            show_array(pointer, size);
            free(pointer);
        }
        printf("Enter the number of elements (<1 to quit): ");
    }
    printf("Done.\n");
    return 0;
}
int *make_array(int el, int val){
    int *tmp = (int*)malloc(el*sizeof(int));
    for(int i=0; i<el; i++){
        tmp[i]=val;
    }
    return tmp;
}
void show_array(const int *array, int n){
    for(int i=0; i<n; i++){
        printf("%d ", array[i]);
    }
    putchar('\n');
}
