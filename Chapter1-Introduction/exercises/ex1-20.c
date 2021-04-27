/**
 * Exercice 1.20
 * 
 *  Write a program `detab` that replaces tabs in the input with the
 * proper number of blanks to space to the next tab stop. Assume a fixed set of
 * tab stops, say every n columns. Should n be a variable or a symbolic parameter? 
 * 
 **/

#include <stdio.h>

#define TABSTOP 8

int main()
{
    int c, n;

    n = 0;
    while ((c = getchar()) != EOF)
    {
        if (c != '\t')
        {
            n++;
            putchar(c);
        }
        if (c == '\t')
            for (; n < TABSTOP; n++)
                putchar(' ');
        if (n >= TABSTOP || c == '\n')
            n = 0;
    }
    return 0;
}