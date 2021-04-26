#include <stdio.h>

/* Copy input to output */
void main()
{
    int c;

    while ((c = getchar()) != EOF) // ctrl + D
        putchar(c);
}