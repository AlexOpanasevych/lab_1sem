/* ----------------------------------------------------------------<Header>-
 Name: task12.4.c
 Title: Task 4 for 12 practice.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2018-11-29
 Revised: _
 Description: Дополните функцию atof таким образом, чтобы она справлялась
    с числами вида 123.456e-6 ,в которых после мантиссы может стоять е
    (или Е) с последующим порядком (быть может, со знаком).
 ------------------------------------------------------------------</Header>-*/
#include <ctype.h>
#include <stdio.h>
#include <math.h>
#define MAXLINE 100

double atof (char s[]);
int mygetline (char line[], int max);
int main(void) {
    double sum;
    char line[MAXLINE+1];
    sum = 0;
    while (mygetline(line, MAXLINE+1) > 0)
        printf ("%g\n", sum += atof(line));
    return 0;
}
/* getline: читает строку в s, возвращает длину */
int mygetline(char s[], int lim) {
    int c;
    int i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n' )
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
/* atof: преобразование строки s в double */
double atof (char s[]) {
    double val, power;
    int i;
    int sign;
    /* игнорирование левых символов-разделителей: */
    for(i = 0; isspace (s[i]); i++);
        sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit (s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] =='.')
        i++;
    for(power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
   //Изменения начинаются тут!
    if(s[i]=='e' || s[i]=='E'){
        if(s[i+1]=='+'){
            if(isdigit(s[i+4])){
                val*=pow(10,((s[i+2]-'0')*100.0+(s[i+3]-'0')*10.0+(s[i+4]-'0')*1.0));
            }else if(isdigit(s[i+3])){
                val*=pow(10,((s[i+2]-'0')*10.0+(s[i+3]-'0')*1.0));
            }else if(isdigit(s[i+2])){
                val*=pow(10,((s[i+2]-'0')*1.0));
            }else puts("Error.");
        } else if(s[i+1]=='-'){
            if(isdigit(s[i+4])){
                power*=pow(10,((s[i+2]-'0')*100.0+(s[i+3]-'0')*10.0+(s[i+4]-'0')*1.0));
            }else if(isdigit(s[i+3])){
                power*=pow(10,((s[i+2]-'0')*10.0+(s[i+3]-'0')*1.0));
            }else if(isdigit(s[i+2])){
                power*=pow(10,((s[i+2]-'0')*1.0));
            }else puts("Error.");}
    }
    //А тут заканчиваются...
    return sign * val / power;
}
/*Результат выполнения:
    1
    1
    2
    3
    3e-1
    3.3
    3e-02
    3.33
    6e+1
    63.33
*/
