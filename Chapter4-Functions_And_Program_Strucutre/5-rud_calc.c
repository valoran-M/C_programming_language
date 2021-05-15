#include <stdio.h>

#define MAXLINE 100

/*
    cc 5-rud_calc.c 4-atof.c 2-getline.c
*/

/* rudimentary calculator */
int main()
{
    double sum, atof(char s[]);
    char line[MAXLINE];
    int get_line(char line[], int max);

    sum = 0;
    while (get_line(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));
    return 0;
}