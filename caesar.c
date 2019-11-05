#include <ctype.h>

#include <string.h>

#include <stdio.h>

#include <stdlib.h>

#define MAX_SIZE 256


void stringInput(char *strin) { // Function for string input by Olexandr Opanasevich
	int counter = 0; // счетчик массива
	printf("Input string, please :\n"); //
	do { // считываем строку
		strin[counter] = getchar(); // 
		counter++; //
	} while(strin[counter-1] != '\n');// do \n
	strin[counter-1] = 0; //---убираем снос строки, который считался и заменяем его символом конца строки
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("Напишіть ключ наступного разу!");
        return 1;
    }
    else
    {
        int k = atoi(argv[1]);
        char *string;
        string = (char*)malloc(MAX_SIZE*sizeof(char));
        stringInput(string);
        for (int i = 0, n = strlen(string); i < n; i++)
        {
            if(isalpha(string[i]))
            {
                if(islower(string[i]))
                {
                    printf("%c", ((((string[i]-97)+k) % 26) + 97));
                }
                else
                {
                    printf("%c", ((((string[i]-65)+k) % 26)+65));
                }
            }
            else
            {
                printf("%c", string[i]);
            }
        }
        {

        }
        printf("\n");
        return 0;
    }
}