#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

void main()
{
    int i = 0777;
    printf("%d\n", getbits(i, 3, 4));
}

/* getbits: get n bits from position p*/
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n) & ~(~0 << n));
}