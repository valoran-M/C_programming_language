/**
 * Exercice 1.13.b
 * 
 *  Write a program to print a histogram of the lenghts of words
 * in its input. It is easy to draw the histogram with the bars horizontal.
 *
 * a vertical orientation is more challenging
 * 
 **/

#include <stdio.h>

#define MAXWORD 20
#define IN 1
#define OUT 0

void main()
{
    int c, nw, state, word, max;
    int wordLength[MAXWORD];

    for (nw = 0; nw < MAXWORD; nw++)
        wordLength[nw] = 0;
    nw = -1;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t' && state == IN)
            state = OUT;
        else if (state == OUT)
        {
            nw++;
            state = IN;
            wordLength[nw]++;
        }
        else
            wordLength[nw]++;
    }

    // print vertical histogram
    max = wordLength[0];
    for (word = 0; word <= nw; word++)
        if (max < wordLength[word])
            max = wordLength[word];
    putchar('\n');
    for (max; max > 0; max--)
    {
        for (word = 0; word <= nw; word++)
        {
            putchar(' ');
            if (wordLength[word] >= max)
                putchar('*');
            else
                putchar(' ');
            putchar(' ');
        }
        putchar('\n');
    }
    for (word = 0; word <= nw; word++)
        printf("---");
    putchar('\n');
}
