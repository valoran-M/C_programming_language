/**
 * Exercice 5.13
 * 
 *  Write the program tail wich prints the last n lines of
 * its input. By default, n is 10, let us say, but it can 
 * be changed by an optional argument, so that
 * 
 *      tails -n
 * 
 * printd the last n lines. The program shoul behave 
 * rationally no matter how unreasonable the input 
 * of the value of n. Write the program so it makes the best
 * use of avaible storage line should be sotred as in 
 * the sorting program of Section 5.6, not
 * int two-dimensional array of fixed size.  
 * 
 **/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 5000 /* max #lines to be sorted */
#define DEFAULT 10    /* Deafult value case argc = 1 */

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int def);

/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines; /* number of input lines read */
    int i = 0;
    int def = 0;

    if (argc == 1)
    {
        printf("Usage: ./tail.out -n | A default value has been set up\n");
        def = DEFAULT;
    }
    else if (argc == 2 && (*++argv)[i] == '-')
    {
        ++i;
        while ((*argv)[i])
        {
            if (isdigit(((*argv)[i])))
                def = 10 * def + (((*argv)[i]) - '0');
            else
            {
                printf("Input must contain only digits leaving....\n");
                return -1;
            }
            ++i;
        }
    }
    else
    {
        printf("Wrong input!(Usage: ./tail.out -n) Leaving...\n");
        return -1;
    }
    if (def > MAXLINES - 1)
    {
        printf("Input too big ! Leaving...\n");
        return -1;
    }
    if (def < 1)
    {
        printf("The value of n must be bigger than 0. Leaving...\n");
        return -1;
    }
    i = 0;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        writelines(lineptr, nlines, def);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000 /* max lenght of any input line */
int lgetline(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = lgetline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else
        {
            line[len - 1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

/* writelines: write output line */
void writelines(char *lineptr[], int nlines, int def)
{
    if (nlines < def)
        while (nlines-- > 0)
            printf("%s\n", *lineptr++);
    else
        while (def-- > 0)
            printf("%s\n", lineptr[nlines - def - 1]);
}

int lgetline(char *s, int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        *(s++) = c;
    if (c == '\n')
    {
        *(s++) = c;
        ++i;
    }
    *s = '\0';
    return i;
}
#define ALLOCSIZE 100000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;  /* next free position */

char *alloc(int n) /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    { /* it fits */
        allocp += n;
        return allocp - n; /* old p */
    }
    else /* not enough room */
        return 0;
}

void afree(char *p) /* free storage pointed to by p */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}