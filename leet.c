#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char dictionary(char what);

char* toLeetSpeak (char *speak)
{
  int size = strlen(speak);
  char *new = (char*)malloc((size + 1) * sizeof(char));
  new[size] = '\0';
  for(int i = 0; i < size; i++)
    new[i] = dictionary(speak[i]);
  return new;
}

char dictionary(char what){
  switch(what){
      case 'A' : return '@';
      case 'B' : return '8';
      case 'C' : return '(';
      case 'E' : return '3';
      case 'G' : return '6';
      case 'H' : return '#';
      case 'I' : return '!';
      case 'L' : return '1';
      case 'O' : return '0';
      case 'S' : return '$';
      case 'T' : return '7';
      case 'Z' : return '2';
      default  : return what;
  }
}

int main(void) {
	char* speak;
	printf("vvedite predlozhenie :\n");
	scanf("%s", speak);
	char * converted = toLeetSpeak(speak);
	printf("%s", converted);
}