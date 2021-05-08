/**
 *  Exercice 2.10
 * 
 *  Rewrite the function lower, which converts
 * upper case letters to lower case, with a conditional
 * expression instead of if-else
 * 
 **/
#include <stdio.h>

void lower(char s[]);

void main()
{
    char s[] = "ABCDEFGHIJ";
    lower(s);
    printf("%s\n", s);
}

/*lower: convert c to lower case; ASCII only */
void lower(char s[])
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
        s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? s[i] + 'a' - 'A' : s[i];
}