/**
 * Exercice 4.9:
 * 
 *  Our getch and ungetch do not handle a pushed-back EOF
 * correctly. DEcied what their properties ought to be if 
 * an EOF is pushed back, then implement your design
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
    int c;

    ungetch(EOF);
    ungets("\nTest");
    while ((c = getch()) != EOF)
        printf("%c", c);
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