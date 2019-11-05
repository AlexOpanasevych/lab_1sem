#include "functions.h"
int StringAnalyserNextTokenId = 0; // public variable for function nextToken.   DO NOT CHANGE!!!

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

void initParser(){
    StringAnalyserNextTokenId = 0;
}

int nextToken(char strin[], int length, char *token, int  tokenLength){
    int tokenIter = 0; // token iterator to write inside the token;
    while(symbolId((int)strin[StringAnalyserNextTokenId]) != 3 || strin[StringAnalyserNextTokenId] == 0){ // skipping spaces and command symbols
        if(strin[StringAnalyserNextTokenId] == 0){ // checking the null symbol. If it's null - then stop function
            token[0] = 0;
            StringAnalyserNextTokenId = 0;
            return 1;
        }
        StringAnalyserNextTokenId++;
    }
    while(StringAnalyserNextTokenId < length && strin[StringAnalyserNextTokenId] != 0 && strin[StringAnalyserNextTokenId] != ' ' && (symbolId((int)strin[StringAnalyserNextTokenId]) == 3/* || symbolId((int)strin[StringAnalyserNextTokenId]) == 1*/)){ // getting the letters of the word
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

