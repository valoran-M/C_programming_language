/**
 *  Exercice 4.1:
 * 
 *  Write the function strrindex(s,t), which returns the position
 * of the rightmost occurrence of t in s, or -1 if there is none
 * 
 **/

#include <stdio.h>
#define MAXLINE 1000

/*
    Compilation : 
        cc ex4-1.c ../2-getline.c
*/

int get_line(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";

/* fund all lines matching pattern */
int main()
{
    char line[MAXLINE];
    int found = 0;

    while (get_line(line, MAXLINE) > 0)
        if (strrindex(line, pattern) >= 0)
        {
            printf("%s", line);
            found++;
        }
    return found;
}

int strrindex(char s[], char t[])
{
    int i, j, k, rightmost;

    rightmost = -1;
    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            rightmost =  i;
    }
    return rightmost;
}