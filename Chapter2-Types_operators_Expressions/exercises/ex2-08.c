/**
 *  Exercie 2.8
 * 
 *  Write a function reightrot(x, n) that return the value of the
 * integer x rotated to the right by n bit position
 *
 **/

#include <stdio.h>

unsigned reightrot(unsigned x, int n);

void main()
{
    printf("%u\n", reightrot(0b00011, 0));
}

unsigned reightrot(unsigned x, int n)
{
    while (n > 0)
    {
        if (x & 1)
            x = (x >> 1) | ~(~0 >> 1);
        else
            x = x >> 1;
        --n;
    }
    return x;
}