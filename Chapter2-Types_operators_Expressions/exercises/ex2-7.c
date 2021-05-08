/**
 *  Exercice 2.7
 * 
 *  Wrtie a funtion invert(x, p, n) that return x with 
 * the n that begin at position p set to the rightmost n
 * bits of y, leaving the other bits unchanged.
 * 
 **/
#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

void main()
{
    printf("%u\n", invert(0b000000, 2, 1)); // 4
    printf("%u\n", invert(0b000000, 3, 1)); // 8
    printf("%u\n", invert(0b000000, 4, 1)); // 16

}

unsigned invert(unsigned x, int p, int n)
{
    return x ^ ((~(~0<<n))<< p+1-n);
}