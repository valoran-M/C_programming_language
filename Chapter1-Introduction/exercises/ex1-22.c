/**
 * Exercice 1.22
 * 
 *  Write a program to "fold" long input lines into two or more
 * shorter lines after the last non-blank character that occurs before the n-th
 * colomn of input. Make sure your program does something intelligent withe very
 * long lines, and if ther are no blanks or tabs before the specifier column.
 * 
 **/

#include <stdio.h>

#define MAXCHAR 100
#define MAX 10

int my_getline(char s[], int lim);
void fold_line(char line[], char fold[], int n_break);

void main()
{
    int len, lineLenLimit, i, j, foldCol;
    char line[MAXCHAR], outputLine[MAXCHAR];

    lineLenLimit = 10;

    while ((len = my_getline(line, MAXCHAR)) > 0)
    {
        fold_line(line, outputLine, 40);
        printf("%s\n", outputLine);
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

void fold_line(char line[], char fold[], int n_break)
{
    int i, j, column, split, last_blank;
    column = split = last_blank = 0;

    for (i = 0, j = 0; line[i] != '\0'; ++i, ++j)
    {
        fold[j] = line[i];

        if (fold[j] == '\n')
            column = 0;

        column++;

        if (column == n_break - MAX)
            split = 1;

        if (split && (fold[j] == ' ' || fold[j] == '\t'))
            last_blank = j;

        if (column == n_break)
        {
            if (last_blank)
            {
                fold[last_blank] = '\n';
                column = j - last_blank;
                last_blank = 0;
            }
            else
            {
                fold[j++] = '-';
                fold[j] = '\n';

                column = 0;
            }
            split = 0;
        }
    }

    fold[j] = '\0';
}