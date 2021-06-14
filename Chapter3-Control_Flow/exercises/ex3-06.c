/**
 * Exercie 3.6 
 * 
 *  Write a version of itoa that accpets three arguments instead
 * of two. The third argument is a minimum fiels width; the 
 * converted number must be padded with blanks on the left
 * if necessary to make it wide enough.
 * 
 **/

#include <stdio.h>
#include <string.h>

#define abs(x) ((x > 0) ? x : -x)

void itoa(int n, char s[], int minal_size);
void reverse(char s[]);

void main()
{
    char s[100];
    itoa(21131, s, 20);
    printf("%s\n", s);
    itoa(-21111131, s, 20);
    printf("%s\n", s);
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[], int minal_size)
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

    while (i < minal_size)
        s[i++] = ' ';

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