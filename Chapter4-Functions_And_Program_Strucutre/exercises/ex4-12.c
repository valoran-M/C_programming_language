/**
 * Exercice 4.12:
 * 
 *  Adapt the ideas of printd to write a recurive version
 * of itoa; that is, convert an integer into a string 
 * by calling a recursive routine.
 * 
 **/

#include <stdio.h>

void itoa(int n, char buffer[]);

int main()
{
    char buffer[20];
    itoa(10, buffer);
    printf("%s\n", buffer);
    itoa(-10, buffer);
    printf("%s\n", buffer);
    itoa(1234, buffer);
    printf("%s\n", buffer);
    return 0;
}

/* itoa: convert integer to string */
void itoa(int n, char s[])
{
    int itoar(int n, char s[], int i);
    itoar(n, s, 0);
}

/* itoar: convert integer to string, recursive version */
int itoar(int n, char s[], int i)
{
    if (n < 0)
    {
        s[i++] = '-';
        n = -n;
    }
    if (n / 10)
        i = itoar(n / 10, s, i);
    s[i++] = n % 10 + '0';
    s[i] = '\0';
    return i;
}