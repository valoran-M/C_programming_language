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

void main()
{
    int len, lineLenLimit,i, j, foldCol;
    char line[MAXCHAR], outputLine[MAXCHAR];

    lineLenLimit = 10;

    while ((len = my_getline(line, MAXCHAR)) > 0)
    {
        for (i = 0; i < len; ++i)
        {
            if (i != 0 && (i + 1) % lineLenLimit == 0)
            {
                for (j = i; j > 0; --j)
                    if (line[j] != ' ' && line[j] != '\t')
                    {
                        foldCol = j;
                        break;
                    }

                for (j = 0; j < foldCol - i + lineLenLimit; ++j)
                    outputLine[j] = line[j + i - lineLenLimit + 1];

                outputLine[j] = '\n';
                outputLine[j + 1] = '\0';

                printf("%s", outputLine);
            }
            else if (i == len - 1)
            {
                for (j = 0; j < i % lineLenLimit; ++j)
                    outputLine[j] = line[j + i - (i % lineLenLimit)];

                outputLine[j] = '\0';
                printf("%s", outputLine);
            }
        }
        putchar('\n');
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
