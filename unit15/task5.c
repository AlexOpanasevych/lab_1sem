/* ----------------------------------------------------------------<Header>-
 Name: task5.c
 Title: Task 5 for 15 practise.
 Group: TI-81
 Student: Opanasevich O.B
 Written: 2018-12-20
 Description: Самая естественная форма алгоритма быстрой сортировки- это рекурсивная (см. Example 15.4). Напишите этот же 
алгоритм в итерационной форме и сравните две его версии.
 ------------------------------------------------------------------</Header>-*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define TEST_LENGTH 20
void swap (int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
/* This function is same in both iterative and recursive*/
int partition (int *arr, int l, int h){
    int x = arr[h];
    int i = (l - 1);

    for (int j = l; j <= h - 1; j++){
        if (arr[j] <= x){
            i++;
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[i + 1], &arr[h]);
    return (i + 1);
}

/* *arr --> Array to be sorted,
   l  --> Starting index,
   h  --> Ending index */
void quickSortIterative (int *arr, int l, int h){
    // Create an auxiliary stack
    int stack[h - l + 1];

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = h;

    // Keep popping from stack while is not empty
    while(top>=0){
        // Pop h and l
        h = stack[top--];
        l = stack[top--];

        // Set pivot element at its correct position
        // in sorted array
        int p = partition(arr, l, h);

        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p-1 > l){
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p+1 < h){
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}

// A utility function to print contents of arr
void printArr(int *arr, int n){
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
}
int *initArray(int len){
    srand(time(NULL));
    int* temp = malloc(len*sizeof(int));
    for(int i = 0; i < len; i++){
        temp[i] = rand()%TEST_LENGTH;//len-i-1;
    }
    return temp;
}
int cmpfunc(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}
int main(void){
    int *arr = initArray(TEST_LENGTH);
    int *tmp = (int*)malloc(TEST_LENGTH*sizeof(int));
    memcpy(tmp, arr, TEST_LENGTH*sizeof(int));
    clock_t time_start = clock();
    quickSortIterative(arr, 0, TEST_LENGTH-1);
    time_start = clock() - time_start;
    printf("Time taken on iterative version: %d seconds and %d milliseconds\n", time_start/CLOCKS_PER_SEC, (time_start*1000/CLOCKS_PER_SEC)%1000);
    printArr(arr, TEST_LENGTH);
    putchar('\n');
    clock_t time_start2 = clock();
    qsort(tmp, (size_t)TEST_LENGTH, sizeof(int), cmpfunc);
    time_start2 = clock() - time_start2;
    printf("Time taken on recursive version: %d seconds and %d milliseconds\n", time_start2/CLOCKS_PER_SEC, (time_start2*1000/CLOCKS_PER_SEC)%1000);
    printArr(tmp, TEST_LENGTH);
    free(tmp);
    free(arr);
    getchar();
    return 0;
}
/*Output:
 PS C:\cygwin64\home\Саня\unit15> ./a
Time taken on iterative version: 0 seconds and 0 milliseconds
0 0 1 1 2 5 6 6 7 7 9 10 10 13 15 15 16 18 20 21 21 22 23 23 24
Time taken on recursive version: 0 seconds and 7 milliseconds
0 0 1 1 2 5 6 6 7 7 9 10 10 13 15 15 16 18 20 21 21 22 23 23 24
*/
