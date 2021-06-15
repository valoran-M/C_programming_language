/**
 * Exercie 4.2
 * 
 *  Write getfloat, the floating-point analog
 * of getint. What type does getfloat return as its
 * function value?
 * 
 **/

#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100

int getfloat(float *pn);

int main()
{
    float i;
    getfloat(&i);
    printf("%f\n", i);
    return 0;
}

int getch(void);
void ungetch(int);

int getfloat(float *pn)
{
    int c, sign;

    while (isspace(c = getch())) /* skip white space */
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c); /* is not a number */
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        if (!isdigit(c = getch()))
        {
            ungetch(c);
            ungetch(sign == 1 ? '+' : '-');
            return 0;
        }

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    if (c == '.')
    {
        float i;
        for( i = 10.; (c = getch()) && isdigit(c); i *= 10.)
            *pn += (c - '0') / i; 
    }

    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}


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