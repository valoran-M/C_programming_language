/**
 * Exercice 4.7:
 * 
 *  Write a routine unget(s) that will push back an 
 * entire string onto the input. Should ungets know 
 * about buf and bufp, or should it just use getch 
 * ungetch ?
 * 
 **/

#include <stdio.h>
#include <string.h>

#define BUFSIZE 100
#define MAXLINE 10000

int getch(void);
void ungetch(int);
void ungets(char[]);

char buf[BUFSIZE];
int bufp = 0;

int main(void)
{
    ungets("Test");
    while (bufp > 0)
        printf("%c", getch());
    putchar('\n');
    return 0;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void ungets(char s[])
{
    int i;
    for (i = strlen(s) - 1; i >= 0; --i)
        ungetch(s[i]);
}