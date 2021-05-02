/**
 * Exercice 2.2
 * 
 *  Write a loop equivalent to the  for loop above
 * without using && or || 
 * 
 * for (i = 0; i < lim - 1 && (c = getchar()) != '\n' &&
 *          c != EOf; i++)
 *      s[i++] = c;
 * 
 **/
#include <stdio.h>

#define MAXCHAR 1000

void main()
{
    char c, s[MAXCHAR];

    int i = 0, loop = 1;

    while (loop)
    {
        c = getchar();
        if (i > MAXCHAR - 1)
            loop = 0;
        else if (c == '\n')
            loop = 0;
        else if (c == EOF)
            loop = 0;
        s[i++] = c;
    }
    s[i] = '\0';
    printf("%s\n", s);
}