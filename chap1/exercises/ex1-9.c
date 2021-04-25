#include <stdio.h>

#define PASSCHAR ' '

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
