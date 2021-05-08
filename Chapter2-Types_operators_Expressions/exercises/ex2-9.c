/**
 *  Exercice 2.9
 * 
 *  In two's complement number systeme, x &= (x-1) delets
 * the rigthmost 1-bit in x. Explain why. Use this observation 
 * to write a faster version of bitcount()
 * 
 **/

/*

    Exemple:
        010101001b - 01b = 010101000b
        010101000b - 01b = 010100111b & 010101000b -> 010100000b

    x - 1 : delete first bite in x but place 
    the bits before 1.
    
    As it was the first bit which was at 1, 
    those before were at 0 with the & we remove all these 1

    So we ended up deleting the first 1

*/

#include <stdio.h>

int bitcount(unsigned x);

void main()
{
    printf("%u\n", bitcount(0b1111));
}

int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; b++)
        x&=(x-1);
    return b;
}