/* ----------------------------------------------------------------<Header>-
 Name: task4.c
 Title: "Adagio"
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2018-12-20
 Description: Задача 15.4. "Адажио"
Разработайте и программно реализуйте алгоритм, сортирующий массив из N целых чисел как
можно медленнее. Алгоритм должен постепенно сходиться к результату и успешно заканчиваться;
нельзя применять такие обманные трюки, как холостые прогоны циклов специально для задержки
времени. Какой порядок O(?) имеет этот алгоритм по отношению к количеству элементов N? 
 Output:
 PS C:\cygwin64\home\Саня\unit15> ./a
Input size of array:
5
3
2
1
4
5
Sorted array :
1 2 3 4 5
Done.
 ------------------------------------------------------------------</Header>-*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp; 
}
// To check if array is sorted or not 
bool isSorted(int *a, int n) { 
    while (n-- > 1) 
        if (a[n] < a[n - 1]) 
            return false; 
    return true; 
} 
  
// To generate permutation of the array 
void shuffle(int *a, int n) { 
    for (int i = 0; i < n; i++) 
        swap(&a[i], &a[rand() % n]); 
    //printf("DEBUG: %d %d\n", a[0], a[n]);
} 

// Sorts array a[0..n-1] using myLowSort
void myLowSort(int *a, int n) { 
    // if array is not sorted then shuffle 
    // the array again 
    while (!isSorted(a, n)) 
        shuffle(a, n); 
}

// prints the array 
void printArray(int *a, int n) 
{ 
    for (int i = 0; i < n; i++) 
        printf("%d ", a[i]); 
    printf("\n"); 
} 

int main() 
{ 
    int size;
    //while(getchar() != '@' && size > 0){
        printf("Input size of array:\n");
        scanf("%d", &size);
        //if(size < 0) continue;
        int *array = (int*)malloc(size*sizeof(int));
        //srand(time(NULL));
        for(int i=0; i< size; i++){
            //array[i] = rand()%100;
            scanf("%d", &array[i]);;
        }
        myLowSort(array, size); 
        printf("Sorted array :\n"); 
        printArray(array, size);
    //}
    printf("Done.\n");
    return 0; 
}