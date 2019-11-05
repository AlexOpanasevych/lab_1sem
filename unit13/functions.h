#include <stdio.h>
#include <string.h>

//Control values
#define STRING "Hello Guys, how are You?\n Today it is raining so hard" // input string
#define OPERATION 1 // input operation: 0 for symbol statistic, 1 for letters per word

#define TRUE 1
#define FALSE 0

//Initialize parser;
void initParser();

//Manual: input code in DEC and get: -1 when error, 0 when small letter, 1 when capital letter, 2 when symbol, 3 when number, 4 when comand symbol or unprintable symbol; 
int symbolId(int DECCode);

//Manual: returns 0 when no errors, 1 when error. Input the string to search, it's length, link to array to write into, maximal length of this array. Used to get next word from the string.   
int nextToken(char strin[], int length, char *token, int  tokenLength);
