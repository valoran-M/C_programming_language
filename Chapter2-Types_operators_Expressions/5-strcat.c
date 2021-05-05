#include <stdio.h>

void my_strcat(char s[], char t[]);

void main()
{
    char s[100] = "abcdefgh";
    char t[] = "ijklmnopqrstuvwxyz";
    printf("%s, + %s = ", s, t);
    my_strcat(s, t);
    printf("%s\n", s);
}

/* strcat: concatenante t to end od s; s must be big enought */
void my_strcat(char s[], char t[])
{
    int i, j;

    i = j = 0;
    while (s[i] != '\0') /* find end of s*/
        i++;
    while ((s[i++] = t[j++]) != '\0') /* copy t */
        ;
}