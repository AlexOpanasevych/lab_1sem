#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "testFunctions.h"

#define OUT 100
char Input[4][OUT] = {"It's a long way to Tipperary","It's a long way to go","It's a long way to little Mary", "To the sweetest girl I know"};
void vigenere(char* array, char *cipherArray, char* keyArray) {
    int keyLength = strlen(keyArray);
    for (int i = 0, j = 0, n = strlen(array); i < n; i++)
    {   
        // if alphabetic proceed with ciphering, else return normal character
        if (isalpha(array[i])) {
            
            // calculate ASCII code for the key position (j), wrap around beginning of keyword when end of keyword is reached
            char keyReferenceValue = (isupper(keyArray[j % keyLength])) ? 'A' : 'a';
            
            // calculate ASCII code of the first letter of alphabet depending on upper- or lowercase
            char referenceValue = (isupper(array[i])) ? 'A' : 'a';
            
            // calculate cipher letter using formula ci = (pi + kj) % 26, then convert to right ASCII character number
            cipherArray[i] = ((array[i] - referenceValue + (keyArray[(j % keyLength)] - keyReferenceValue)) % 26) + referenceValue;
            
            // printf("%c %i %i %i %i %i\n", cipher, j, strlen(key), key[(j % keyLength)], referenceValue, rotate);
           
            // increment key position (j) so next letter in key is used
            j++;
        }
        else {
            // output all non-alphabetical chars normally
            cipherArray[i] = array[i];
        }
    }
}

void HackVigenere(char* array, char *cipherArray, char* keyArray) {
    //printf("\nI'm in function\n");
    int keyLength = strlen(keyArray), i, j, arrayLength = strlen(array);
    
    for (i = 0, j = 0; i < arrayLength; i++)
    {   
        if (isalpha(array[i])) {
            
            char keyReferenceValue = (isupper(keyArray[j % keyLength])) ? 'A' : 'a';
            
            char referenceValue = (isupper(cipherArray[i])) ? 'A' : 'a';
            
            array[i] = (((cipherArray[i] - referenceValue) + 26 - (keyArray[(j % keyLength)] - keyReferenceValue)) % 26) + referenceValue;
            
            //printf("%i %i %i %i %i\n", array[i], j, keyLength, keyArray[(j % keyLength)], referenceValue);
           
            j++;
        }
        else {
            array[i] = cipherArray[i];
        }
    }
}

/*void perebor(char *keyArray, int index, char *cipherArray, char *array, int keyLength)  {
    if(index < keyLength) {
        int arrayLength = strlen(array);
        for (int i = 65; i < 91; i++) {
            printf("%s\n", array);
            keyArray[index] = (char)i;
            if (index < keyLength-1) {
                perebor(keyArray, index + 1, cipherArray, array, keyLength);
            }else {
                char *DecryptedArray = (char*)malloc(arrayLength*sizeof(char));
                HackVigenere(DecryptedArray, cipherArray, keyArray);
                if(!strcmp(array, DecryptedArray)) {
                    printf("KEY - %s\n", keyArray);
                    printf("Decrypted text - %s; \n\n", DecryptedArray);
                }
                printf("%s\n", DecryptedArray);
                free(DecryptedArray);
            }
        }
    }
}*/

void RecursionGenerateCombinations(char *cipherArray, char *arBuffer, int order, char *keyArray) {
    int keyLength = strlen(keyArray);
    char* out = (char*)malloc(keyLength*sizeof(char));
        if (order < keyLength) {
                for (int i = 65; i <= 90; i++)
                {
                    if (strcmp(out, arBuffer) == 0){
                        printf("1\n");
                        break;
                }
                    keyArray[order] = (char)i;
                    RecursionGenerateCombinations(cipherArray, arBuffer, order+1, keyArray);
                }
            }
            else{
                
                HackVigenere(out, cipherArray, keyArray);
                printf("%s\n", keyArray);
                free(keyArray);
            }        
}
        //printf("I'm in end of function\n");
int main(){
    int g;// i- це номер в тексте j- номер символа в ключі
    printf("give an array size :\n");
    scanf("%d", &g);
    getchar();   
    char *plainText = (char*)malloc(g*sizeof(char));
    char *cipherArray = (char*)malloc(g*sizeof(char));
    stringInput(plainText);
    printf("phrase - %s\n", plainText);
    char *k = (char*)malloc(g*sizeof(char)); 
    stringInput(k);  // plainText - це текст k - це ключ
    printf("key - %s\n", k);
    vigenere(plainText, cipherArray, k);
    printf("%s\n", cipherArray);
    //char* hackArray = (char*)malloc(n*sizeof(char));
    clock_t before = clock();
    RecursionGenerateCombinations(cipherArray, plainText, 0, k);
    clock_t difference = clock() - before;
    int msec = difference*1000/CLOCKS_PER_SEC;
    printf("Time taken - %i msec\n", msec);
    return 0;
}