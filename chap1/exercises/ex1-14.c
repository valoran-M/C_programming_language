/**
 * Exercice 1.14
 * 
 *  Write a program to print a histogram of the frequencies  of
 * different character in its input.
 * 
 **/

#include <stdio.h>

void main()
{
    int c, i, max;
    int nChar[26];

    for (i = 0; i < 27; i++)
        nChar[i] = 0;

    while ((c = getchar()) != EOF)
    {
        if (c >= 'a' && c <= 'z')
            nChar[c - 'a']++;
        else if (c >= 'A' && c <= 'Z')
            nChar[c - 'A']++;
    }

    // print vertical histogram
    max = nChar[0];
    for (i = 0; i < 26; i++)
        if (max < nChar[i])
            max = nChar[i];

    putchar('\n');
    for (max; max > 0; max--)
    {
        for (i = 0; i < 26; i++)
        {
            putchar(' ');
            if (nChar[i] >= max)
                putchar('*');
            else
                putchar(' ');
            putchar(' ');
        }
        putchar('\n');
    }

    for (i = 0; i < 26; i++)
        printf("-%c-", 'a' + i);
    putchar('\n');
}