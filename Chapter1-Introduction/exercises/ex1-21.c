/**
 * Exercice 1.21
 * 
 *  Write a program entab that replaces strings of blanks by the 
 * minimum number of tabs and blacks to achieve the same spacing. Use the
 * same tab stops as for detab. When either a tab or a single blank would
 * suffice to reac a tab stops
 * 
 **/

#include <stdio.h>

#define TABSTOP 8

void main()
{
    int c, n, blank;

    n = blank = 0;
    while ((c = getchar()) != EOF)
    {
        n++;
        if (c != ' ')
        {
            if (blank > 0)
            {
                for (; blank > 0; blank--)
                    putchar(' ');
                blank = 0;
            }
            putchar(c);
        }
        if (c == ' ')
        {
            blank++;
            if (n == TABSTOP)
            {
                putchar('\t');
                blank = 0;
            }
        }
        if (n >= TABSTOP || c == '\n')
            n = 0;
    }
}