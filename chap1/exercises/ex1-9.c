#include <stdio.h>

#define PASSCHAR ' '

/* 
Write a program to copy its input to its output, replacing each
string of one or more balks by a single blank
*/
void main()
{
    int c, last;

    last = PASSCHAR + 1;
    while ((c = getchar()) != EOF)
    {
        if (c != ' ')
            putchar(c);
        if (c == ' ')
            if (last != ' ')
                putchar(c);
        last = c;
    }
}
