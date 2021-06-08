#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ingetch: too many characters\n");
    else
        buf[bufp++] = c;
}

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