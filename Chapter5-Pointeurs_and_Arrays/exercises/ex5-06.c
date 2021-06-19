/**
 * Exercice 5.6
 * 
 *  Rewrite appropriate programs from earlier 
 * chapters and exercices with pointers instead 
 * of array indexing. Good possibilities include
 * getline, atoi, itoa, and thier variants, 
 * reverse, and strindex and getop.
 * 
 **/

#include <stdio.h>

void get_line(char *s)
{
    while ((*s = getchar()) != EOF && (*s != '\n'))
        ++s;

    *s = '\0';
}

int atoi(const char *s)
{
    int i = 0;

    while (*s != '\0' && *s > '0' && *s < '9')
    {
        i = i * 10 + *s - '0';
        ++s;
    }

    return i;
}

void itoa(char *s, int n)
{
    void reverse(char *s);
    char *t = s;

    while (n)
    {
        *(t++) = n % 10 + '0';
        n /= 10;
    }

    *t = '\0';

    reverse(s);
}

void reverse(char *s)
{
    char *t = s + strlen(s) - 1;
    char aux = 0;

    if (*s == '\0')
        return;

    while (s < t)
    {
        aux = *t;
        *t-- = *s;
        *s++ = aux;
    }
}

int strindex(char *s, char *t)
{
    char *first;
    char *second;
    int pos = 0;

    while (*s++ != '\0')
    {
        ++pos;

        if (*s == *t)
        {
            first = s;
            second = t;

            while (*first++ == *second++)
                if (*second == '\0')
                    return pos;
        }
    }

    return -1;
}

int getop(char *s)
{
    char c;

    while ((*s = c = getchar()) != ' ' || c != '\t')
        ;

    *(s + 1) = '\0';

    if (!isdigit(c) && c != '.')
        return c;

    if (isdigit(c) && c != '.')
        while (isdigit(*(++s) = c = getchar()))
            ;

    if (c == '.')
        while (isdigit(*(++s) = c = getchar()))
            ;

    if (c != EOF)
        ungetc(c, stdin);

    *s = '\0';

    return '0';
}