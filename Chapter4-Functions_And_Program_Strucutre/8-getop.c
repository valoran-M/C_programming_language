#include <stdio.h>
#include <ctype.h>
#include "10-calc.h"

/* getop: get next opertaotr or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    i = 0;

    if(islower(c))
    {
        s[0] = toupper(c);
        return VARSET;
    }else if(isupper(c))
    {
        s[0] = c;
        return VARGET;
    }

    if (c == '-') /* check sign */
        if (!isdigit(s[++i] = c = getch()))
        {
            ungetch(c);
            c = s[0]; /* not a sign */
        }

    if (!isdigit(c) && c != '.')
        return c; /* not a number */

    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}