/**
 * Exercice 1.12
 * 
 *  Write a program that prints its input one word per line
 * 
 **/

#include <stdio.h>

#define IN 1
#define OUT 0

void main()
{
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF)
    {
        if (c != ' ' && c != '\t' && c != '\n')
        {
            state = IN;
            putchar(c);
        }
        else if (state == IN)
        {
            state = OUT;
            putchar('\n');
        }
    }
}