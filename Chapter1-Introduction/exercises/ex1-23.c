/**
 * Exercice 1.23
 * 
 *  Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constants properly.
 * C comments do not nest.
 * 
 **/

#include <stdio.h>

#define MAXCHAR 1000

int my_getline(char s[], int lim);
void removeComment(char in[], char out[], int size);

int blockComment = 0;

void main()
{
    int len = (1 == 1);
    char line[MAXCHAR], outputLine[MAXCHAR];
    while ((len = my_getline(line, MAXCHAR)) > 0)
    {
        removeComment(line, outputLine, len);
        printf("%s", outputLine);
    }
}

/* getline: read a line into s, return length */
int my_getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        i++;
    }
    if (i == 1 && c == '\n')
        i = 0;
    s[i] = '\0';
    return i;
}

void removeComment(char in[], char out[], int size)
{
    extern int blockComment;
    int i, realSize, comment, string;
    realSize = comment = string = 0;

    for (i = 0; i <= size; i++)
    {

        if (in[i] == '\'' || in[i] == '"')
        {
            if (string)
                string = 0;
            else
                string = 1;
        }
        else if (in[i] == '/' && in[i + 1] == '/' && !string)
            comment = 1;
        else if (in[i] == '/' && in[i + 1] == '*' && !string)
            blockComment = 1;
        else if (in[i] == '\n')
            comment = 0;
        else if (blockComment)
            if (in[i - 1] == '/' && in[i - 2] == '*')
                blockComment = 0;

        if (!(comment || blockComment))
        {
            out[realSize] = in[i];
            realSize++;
        }
    }
    if (realSize == 0)
        out[0] = '\0';
}