/**
 * Exercice 4.10:
 * 
 *  An alternate organization uses getline to 
 * read an entire input line; this makes getch and 
 * ungetch unnecessary. Revise the calculator to 
 * use this approach.
 * 
 **/

/*
    The calculator has been changed in the course
*/

#include <stdio.h>
#include <stdlib.h>

int getLine(char s[], int lim)
{
    int c = 0, i = 0;
    for (i = 0; (c = s[i] = getchar()) != EOF && c != '\n' && --lim > 0; i++)
        ;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int main()
{
    char s[100];
    getLine(s, 100);
    printf("%s\n", s);
    return 0;
}