/**
 *  Exercice 2.4
 * 
 *  Write an alternate version of squeeze(s1, s2) that
 * deletes in string s1 that matches any character in 
 * the string s2.
 * 
 **/

#include <stdio.h>

void squeeze(char s1[], char s2[]);

void main()
{
    char s1[] = "abcdefgh\n\n";
    char s2[] = "aceg\n";
    squeeze(s1, s2);
    printf("%s\n", s1);
}

void squeeze(char s1[], char s2[])
{
    int i, j, y, in;

    for (i = j = 0; s1[i] != '\0'; i++)
    {
        in = 0;
        for(y = 0; s2[y] != '\0'; y++)
            if(s2[y] == s1[i])
                in = 1;
        if (!in)
            s1[j++] = s1[i];
    }
    s1[j] = '\0';
}