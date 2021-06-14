/**
 * Exercice 3.4
 * 
 *  In a two's complement number representation, our version of
 * itoa does not handle the largest negative number, that is,
 * the value of n equal to -(2^wordsize-1). Explain why not.
 * Modify it to print the value correctly, regardless of the 
 * machine on which it runs.
 * 
 **/

/*
When the number is too large, the conversion of n into positive
is not possible because n is signed
*/

#include <stdio.h>
#include <string.h>

#define abs(x) ((x > 0) ? x : -x)

void itoa(int n, char s[]);
void reverse(char s[]);

void main()
{
    char s[100];
    itoa(21131, s);
    printf("%s\n", s);
    itoa(-21111131, s);
    printf("%s\n", s);
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;

    sign = n;
    i = 0;
    do /* generate digits in reverse order */
    {
        s[i++] = abs(n % 10) + '0';
    } while (n /= 10);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}