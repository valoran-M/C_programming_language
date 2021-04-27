/**
 * 
 * Exercice 1.19
 * 
 *  Write a function reverse(s) that reverses the charater string s.
 * Use it to write a program that reverses its input a line at time. 
 * 
 **/

#include <stdio.h>

#define MAXLINE 1000

int my_getline(char line[], int maxline);
void reverse(char from[], char to[], int size);

void main()
{
    int len;            /* current line length */
    char line[MAXLINE]; /* current input line */
    char reversLine[MAXLINE];

    while ((len = my_getline(line, MAXLINE)) > 0)
    {
        reverse(line, reversLine, len);
        printf("%s\n", reversLine);
    }
}

/* getline: read a line into s, return length */
int my_getline(char s[], int lim)
{
    int c, i, prec;

    prec = ' ' + 1;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        if (c == '\t')
            s[i] = ' ';
        if (prec == ' ' && c == ' ')
            i--;
        else
            s[i] = c;
        prec = c;
    }

    if (i == 0)
        return 0;

    if (c == '\n')
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

void reverse(char from[], char to[], int size)
{
    int i;
    for (i = 2; i <= size; i++)
        to[i - 2] = from[size - i];
    to[i] = '\0';
}