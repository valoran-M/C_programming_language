/**
 * Exercice 4.11:
 * 
 *  Modify getop so that it doesn't need to use ungetch.
 *  hint: use an internal static variable
 * 
 **/

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000
#define MAXOP 100
#define NUMBER '0'
#define MATHLIB '1'
#define VARIABLE '2'

int getop(char s[])
{
    static int buf = EOF;
    int i, c, c2;

    while ((s[0] = c = (buf == EOF ? getch() : buf)) == ' ' || c == '\t')
        buf = EOF;
    buf = EOF;
    s[1] = '\0';

    i = 0;

    if (!isdigit(c) && c != '.' && c != '-')
    {
        if (c == '=')
        {
            c2 = (buf == EOF ? getch() : buf);
            buf = EOF;
            if (isalpha(c2))
            {
                s[0] = c2;
                return VARIABLE;
            }
            else if (c2 != EOF)
            {
                buf = c2;
            }
        }
        return c; /* not a number */
    }

    if (c == '-')
    {
        c2 = (buf == EOF ? getch() : buf);
        buf = EOF;
        if (c2 != EOF)
            buf = c2;
        if (!isdigit(c2) && c2 != '.')
            return c;
    }
    if (isdigit(c) || c == '-') /* collect integer part */
        while (isdigit(s[++i] = c = (buf == EOF ? getch() : buf)))
        {
            buf = EOF;
        }

    buf = EOF;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = (buf == EOF ? getch() : buf)))
            buf = EOF;
    buf = EOF;
    s[i] = '\0';
    
    if (c != EOF)
        buf = c;
    return NUMBER;
}
