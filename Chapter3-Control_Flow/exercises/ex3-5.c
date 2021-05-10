/**
 * Exercie 3.5
 * 
 *  Write the function itob(n, s, b) that convert the ineger n
 * into a base b character representation in string s. In 
 * particular, itob(n, s, 16) format n as hexadecimal 
 * integer in s
 * 
 **/

#include <stdio.h>
#include <string.h>

#define abs(x) ((x > 0) ? x : -x)

void itob(int n, char s[], int b);
void reverse(char s[]);

void main()
{
    char s[100];
    itob(21131, s, 16);
    printf("%s\n", s);
    itob(-21111131, s, 16);
    printf("%s\n", s);
}

void itob(int n, char s[], int b)
{
    int i, sign, abs_n;

    sign = n;
    i = 0;
    do /* generate digits in reverse order */
    {
        abs_n = abs(n % b);
        s[i++] = abs_n + ((abs_n > 10) ? 'A' - 10 : '0');
    } while (n /= b);

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