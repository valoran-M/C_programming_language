#include <stdio.h>

#define MAXWORD 20
#define IN 1
#define OUT 0

/*
Whrite a porgram to print a histogram of the lenghts of words
in its input. It is easy to draw the histogram with the bars horizontal.
*/
void main()
{
    int c, nw, state, word;
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

    // print horizontal histogram
    for (word = 0; word <= nw; word++)
    {
        printf("|\n|");
        for (int ch = 0; ch < wordLength[word]; ch++)
            putchar('*');
        putchar('\n');
    }
    printf("|\n");
}
