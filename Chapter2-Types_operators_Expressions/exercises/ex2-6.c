/**
 *  Exercice 2.6
 * 
 *  Write a function setbits(x, p, n, y) that return x with
 * the n bits tha begin at position p set to the rightmost
 * n bits of y, leaving the other bits unchanged.
 *
 **/
#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

void main()
{
    printf("%d\n", setbits(0707 , 15, 8, 070));
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    p++;
    // xxxx0000xxxx
    unsigned x_bits = x & ~(~(0 << n) << (p -  n));

    // 0000yyyy0000
    unsigned y_bits = (y & ~(~0 << n)) << (p -  n);

    return x_bits | y_bits;
}