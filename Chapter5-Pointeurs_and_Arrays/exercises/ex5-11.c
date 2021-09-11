/**
 * Exercice 5.11
 * 
 *  Modify the programs entab and detab (written
 * as exercices in Chapter 1) to accept a list of tab stops as arguments.
 * Use the default tab settings is there are no arguments.
 * 
 **/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define DEFAULT 4

int detab(int TABSTOP)
{
    int c, n;

    n = 0;
    while ((c = getchar()) != EOF && c != '\n')
    {
        if (c != '\n' && c != '\t')
        {
            ++n;
            ;
            putchar(c);
        }
        if (c == '\t')
            while (n++ < TABSTOP)
                putchar(' ');
        if (n >= TABSTOP || c == '\n')
            n = 0;
    }
    return 0;
}

int entab(int TABSTOP)
{
    int c, spc, column;

    spc = column = 0;
    while ((c = getchar()) != EOF && c != '\n')
    {
        if (spc == 0 && c != '\n' && c != ' ')
        {
            column++;
            putchar(c);
        }
        if (spc > 0 && c != ' ' && spc >= TABSTOP)
        {
            while (spc >= TABSTOP)
            {
                putchar('\t');
                spc -= TABSTOP;
            }
            while (column > 0)
            {
                putchar(' ');
                column--;
            }
            if (spc == 0)
                putchar(c);
        }
        if (spc > 0 && c != ' ' && spc < TABSTOP)
        {
            while (spc > 0 && spc < TABSTOP)
            {
                putchar(' ');
                spc--;
            }
            putchar(c);
        }
        if (c == ' ')
            spc++;
        if (column >= TABSTOP || c == '\n' || c == '\t')
            column = 0;
    }
    return 0;
}

int check_arg(char *s)
{
    int digit = 0;

    while (*s != '\0')
    {
        if (isdigit(*s))
            digit = digit * 10 + (*s - '0');
        else
        {
            printf("Input must contain only digits\nLeaving......\n");
            exit(EXIT_FAILURE);
        }
        s++;
    }
    return digit;
}

int main(int argc, char *argv[])
{
    int i;

    if (argc == 1)
    {
        printf("Usage: ./a.out arg1 arg2 arg3\nDefault value has been setup\n");
        printf("Testing detab func\n");
        detab(DEFAULT);
        printf("\nTesting entab func\n");
        entab(DEFAULT);
    }
    else
    {
        for (i = 1; argv[i] != NULL; i++)
        {
            printf("\nTesting detab func TABSTOP set = %s\n", argv[i]);
            detab(check_arg(argv[i]));
        }
        for (i = 1; argv[i] != NULL; i++)
        {
            printf("\nTesting entab func TABSTOP set = %s\n", argv[i]);
            entab(check_arg(argv[i]));
        }
    }
    return 0;
}