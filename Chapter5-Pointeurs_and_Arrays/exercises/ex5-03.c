/**
 * Exercice 5.3:
 * 
 *  Write a pointer version of the function strcat that 
 * we showed in Chapter 2: strcat(s, t) copies the string t
 * to the end of s.
 * 
 **/

#include <stdio.h>

void my_strcat(char s[], char t[]);

void main()
{
    char s[100] = "abcdefgh";
    char t[] = "ijklmnopqrstuvwxyz";
    printf("%s + %s = ", s, t);
    my_strcat(s, t);
    printf("%s\n", s);
}

/* strcat: concatenante t to end od s; s must be big enought */
void my_strcat(char s[], char t[])
{
    while (*++s != '\0') /* find end of s*/
        ;
    while (*s++ = *t++) /* copy t */
        ;
}