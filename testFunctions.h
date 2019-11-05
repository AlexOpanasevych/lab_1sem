#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

#define MAX_FLOAT 2147483647
#define MIN_FLOAT -2147483648
#define MAX_SIZE 256
#define CLI_BUFFER_SIZE 10 // максимум буфер
 // input operation: 0 for symbol statistic, 1 for letters per word
#define TRUE 1
#define FALSE 0

int stupidAnalyzer() {
	char massiv[MAX_SIZE];
	printf("Print 'yes' or 'no' :\n");
	scanf("%s", massiv);
	while(!(massiv[0] == 'y' && massiv[1] == 'e' && massiv[2] == 's' && massiv[3] == 0) && !(massiv[0] == 'n' && massiv[1] == 'o' && massiv[2] == 0)) {
		printf("\nIncorrect input. Try again!\n");
		scanf("%s", massiv);
	}
	if(massiv[0] == 'y' && massiv[1] == 'e' && massiv[2] == 's' && massiv[3] == 0) {
		return 1;
	}
	if(massiv[0] == 'n' && massiv[1] == 'o' && massiv[2] == 0) {
		return 0;
	}
	return 0;
}
int stupidAnalyzerCalc() {
	char massiv[MAX_SIZE];
	printf("Print number of operation :\n");
	scanf("%s", massiv);
	while(!(massiv[0] == '1' && massiv[1] == 0) && !(massiv[0] == '2' && massiv[1] == 0) && !(massiv[0] == '3' && massiv[1] == 0) && !(massiv[0] == '4' && massiv[1] == 0)) {
		printf("\nIncorrect input. Try again!\n");
		scanf("%s", massiv);
	}
	if(massiv[0] == '1' && massiv[1] == 0) {
		return 1;
	}
	if(massiv[0] == '2' && massiv[1] == 0) {
		return 2;
	}
	if(massiv[0] == '3' && massiv[1] == 0) {
		return 3;
	}
	if(massiv[0] == '4' && massiv[1] == 0) {
		return 4;
	}
	return 0;
}

int cli_read_float(float *value, const char *prompt) 
{
    size_t length = 0;
    char *end = NULL;
    char buf[CLI_BUFFER_SIZE] = "";
 
    /* Проверка параметров */
    assert(value);
    assert(prompt);
 
    /* Приглашение */
    printf("%s: ", prompt);
    fflush(stdout);
 
    /* Чтение в буфер */
    if (!fgets(buf, sizeof(buf), stdin)) {
        return 1;
    }
 
    /* Удаление символа перевода строки */
    length = strlen(buf);
    if (buf[length - 1] == '\n') {
        buf[--length] = '\0';
 
        /* Перевод из строки в число */
        errno = 0;
        *value = strtof(buf, &end);
 
        /* Обработка ошибок */ 
        if (length == 0) {
            fprintf(stderr, "Ошибка: введена пустая строка.\n");
            return 1;
        }
        if (errno != 0 || *end != '\0') {
            fprintf(stderr, "Ошибка: некорректный символ.\n");
            fprintf(stderr, "\t%s\n" , buf);
            fprintf(stderr, "\t%*c\n", (int)(end - buf) + 1, '^');
            return 1;
        }
    }
    else {
        /* Строка прочитана не полностью
           Пропустить остаток строки      */
        scanf("%*[^\n]");
        scanf("%*c");
        fprintf(stderr, "Ошибка: не вводите больше чем %d символа(ов).\n", CLI_BUFFER_SIZE - 2);
 
        return 1;
    } 
 
    return 0;
}

float cli_read_float1() {
	int status;
	float value;
	do {
		status = cli_read_float(&value, "Give me a float please");
		if (status != 0) {
			printf("Please try again:\n");
		}
	} while (status != 0);
    printf("-----> Вы ввели: %f\n", value);
    return value;
}

int stupidAnalyzerMenu() {
	char massiv[MAX_SIZE];
	printf("Print number of function :\n");
	scanf("%s", massiv);
	while(!(massiv[0] == '1' && massiv[1] == 0) && !(massiv[0] == '2' && massiv[1] == 0) && !(massiv[0] == '3' && massiv[1] == 0) && !(massiv[0] == '4' && massiv[1] == 0) && !(massiv[0] == '5' && massiv[1] == 0) && !(massiv[0] == '6' && massiv[1] == 0) && !(massiv[0] == '7' && massiv[1] == 0)) {
		printf("\nIncorrect input. Try again!\n");
		scanf("%s", massiv);
	}
	if(massiv[0] == '1' && massiv[1] == 0) {
		return 1;
	}
	if(massiv[0] == '2' && massiv[1] == 0) {
		return 2;
	}
	if(massiv[0] == '3' && massiv[1] == 0) {
		return 3;
	}
	if(massiv[0] == '4' && massiv[1] == 0) {
		
		return 4;
	}
	if(massiv[0] == '5' && massiv[1] == 0) {
		
		return 5;
	}
	if(massiv[0] == '6' && massiv[1] == 0) {
		
		return 6;
	}
	return 7;
}

int binsearch(int begin, int end) {
	int choice;	//если 0 то меньше, если 1 то больше//
	if(end - begin != 0 && end - begin != 1) {
		printf("Is your number higher than %d?\n", begin+(end-begin)/2);
		choice = stupidAnalyzer();	//Нужна проверка от дурака. Ищет само число. Если 0 то меньше, если 1 то больше
		if(choice == 0) {
			return binsearch(begin, begin+(end-begin)/2);
		} else {
			return binsearch(begin+(end-begin)/2, end);
		}
	} else {
		return begin;
	}
}

int guesser() {
	int flag = 1; //0 если меньше, 1 если больше
	int range = 10;
	int number;
	while(flag) {
		range *= 10;
		printf("Is your number higher than %d?\n", range);
		flag = stupidAnalyzer();		//Начальное определение отрезка (например от 0 до 100 или от 100 до 1000 и тд), нужна проверка от дурака. 0 если число меньше, 1 если больше
	}
	
	number = binsearch(0, range);
	return number;
}

float calculator(float first_number, float second_number, int id) {
	if(id == 1) {
		return first_number+second_number;	//adding
	}
	if(id == 2) {
		
		return first_number-second_number;	//subtracting
	}
	if(id == 3) {
		
		return first_number*second_number;	//multiplying
	}
	if(id == 4) {
		return first_number/second_number;	//dividing
	}
	return 0;
}

void charCodes(char strin[], int length){
    for(int i=0; i<length; i++){ // goes along whole string
        switch (strin[i]) {  // searching for unprintable symbols and pulling them out;
            case'\n':
                printf("\n symbol '\\n', ASCII - %d", (int)strin[i]); 
                break;
            case '\t':
                printf("\n symbol '\\t', ASCII - %d", (int)strin[i]); 
                break;
            case '\r':
                printf("\n symbol '\\r', ASCII - %d", (int)strin[i]); 
                break;
            default: // if strin[i] not unprintable, then write it;
                printf("\n symbol '%c', ASCII - %d", strin[i], (int)strin[i]);
                break;
        }

    }
}

void name_asker(char name[MAX_SIZE]) { // функция которая спрашивает имя
	int counter = 0; // счетчик массива
	printf("Say your name, please :\n"); //
	do { // спрашиваем имя
		name[counter] = getchar(); // 
		counter++; //
	} while(name[counter-1] != '\n');// do \n
	name[counter-1] = 0; //---убираем снос строки, который считался и заменяем его символом конца строки
}

void stringInput(char strin[MAX_SIZE]) { // функция которая спрашивает имя
	int counter = 0; // счетчик массива
	printf("Input string, please :\n"); //
	do { // спрашиваем имя
		strin[counter] = getchar(); // 
		counter++; //
	} while(strin[counter-1] != '\n');// do \n
	strin[counter-1] = 0; //---убираем снос строки, который считался и заменяем его символом конца строки
}

void MENU() { // функция, выводящая пункты меню
	//printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("__________________________________________________________\n");
	printf("********|-----------MENU----------|***********************\n");
	printf("**********************************************************\n");
	printf("********| Choose your function |**************************\n");
	printf("**********************************************************\n");
	printf("* 1.                   chars counter                     *\n");
	printf("* 2.                   input-output                      *\n");
	printf("* 3. number of uppercase, lowercase letters and symbols  *\n");
	printf("* 4.         average number of letters in words          *\n");
	printf("* 5.                 guessing program                    *\n");
	printf("* 6. addition, subtraction, multiplication or division   *\n");
	printf("* 7.                        Exit                         *\n");
	printf("**********************************************************\n");
}



//Manual: input code in DEC and get: -1 when error, 0 when small letter, 1 when capital letter, 2 when symbol, 3 when number, 4 when comand symbol or unprintable symbol; 
int symbolId(int DECCode){
    if(DECCode >= 97 && DECCode <= 122){ // small letters region in ASCII
        return 0;
    }
    if(DECCode >= 65 && DECCode <= 90){ // capital letters region in ASCII
        return 1;
    }
    if((DECCode >= 33 && DECCode <= 47) || (DECCode >= 58 && DECCode <= 64) || (DECCode >= 91 && DECCode <= 96) || (DECCode >= 123 && DECCode <= 126)){ // symbols region in ASCII
        return 2;
    }
    if((DECCode >= 48 && DECCode <= 57)){ // numbers region in ASCII
        return 3;
    }
    if((DECCode >= 0 && DECCode <= 32)){ // comand symbols or unprintable symbols region in ASCII
        return 4;
    }

    return -1;
}

//Manual: input the string and it's length. Funcction pulling out to stdin the number of small/capital letters and symbols. 
void symbolCount(char strin[], int length){
    int smallLettersCounter = 0; // The counter of small letters in the string
    int capitalLettersCounter = 0; // The counter of capital letters in the string
    int symbolsCounter = 0; // The counter of symbols in the strings
    for(int i=0; i<length; i++){
        switch (symbolId((int)strin[i])){ // determining which character is strin[i]  
            case 0: 
                smallLettersCounter++;
                break;
            case 1: 
                capitalLettersCounter++;
                break;
            case 2: 
                symbolsCounter++;
                break;
            default: 
                break;
       }
    }
    printf("\nIn your string: small letters - %d, capital letters = %d, symbols - %d", smallLettersCounter, capitalLettersCounter, symbolsCounter);
}

//Manual: returns 0 when no errors, 1 when error. Input the string to search, it's length, link to array to write into, maximal length of this array. Used to get next word from the string.   
int StringAnalyserNextTokenId = 0; // public variable for function nextToken.   DO NOT CHANGE!!!
int nextToken(char strin[], int length, char *token, int  tokenLength){
    int tokenIter = 0; // token iterator to write inside the token;
    while(symbolId((int)strin[StringAnalyserNextTokenId]) > 1 || strin[StringAnalyserNextTokenId] == 0){ // skipping spaces and command symbols
        if(strin[StringAnalyserNextTokenId] == 0){ // checking the null symbol. If it's null - then stop function
            token[0] = 0;
            StringAnalyserNextTokenId = 0;
            return 1;
        }
        StringAnalyserNextTokenId++;
    }

    while(StringAnalyserNextTokenId < length && strin[StringAnalyserNextTokenId] != 0 && strin[StringAnalyserNextTokenId] != ' ' && (symbolId((int)strin[StringAnalyserNextTokenId]) == 0 || symbolId((int)strin[StringAnalyserNextTokenId]) == 1)){ // getting the letters of the word
        if(tokenIter > tokenLength){ // Checking for error if word width higher then maximal available space to write into;
            return 1;
        } 
        token[tokenIter] = strin[StringAnalyserNextTokenId]; // writing symbol from string to token word
        StringAnalyserNextTokenId++;
        tokenIter++; 
    }
    if(tokenIter > tokenLength){ // Checking for error if word width higher then maximal available space to write into;
        return 1;
    } 
    token[tokenIter] = 0; // adding null symbol in the end of word
    return 0;
}

//Manual: input the string and it's length. Get the average letters per words in input string;
int wordsSymbolStatistic(char strin[], int length){
    int wordsCount = 0; // the counter of words in string
    int lettersCount = 0; // the counter of letters in string
    char token[256];
    while(nextToken(strin, length, token, 256) == 0){ // reads the words from string to token while not EOL
        wordsCount++; // countiing the words
        lettersCount += strlen(token); // counting the letters
    }
    return (lettersCount/wordsCount); // calculating and returning the average symbols per word
}

//Manual input the string, it's lenght and task id. For task three id - 0, for task four id - 1; 
void stringAnalyser(char strin[], int length, int taskId){
    if(taskId == 0){
        symbolCount(strin, length);
    }else{
        printf("\nAverage count of symbols per word is: %d", wordsSymbolStatistic(strin, length));
    }
}