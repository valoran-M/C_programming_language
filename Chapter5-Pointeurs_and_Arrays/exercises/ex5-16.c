/**
 * Exercice 5.16
 *
 *  Add the -d ("directory order") option, wich makes comparisons
 * only on letter, numbers and blanks. Make sur it works in conjuction
 * wich -f
 * 
 **/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void write_lines(char *lineptr[], int nlines);

void my_qsort(void *lineptr[], int left, int right, int reverse,
              int (*comp)(void *, void *));
int numcmp(const char *, const char *);
int strcmpignore(const char *s1,const char *s2);

/* sort input lines */
int main(int argc, char const *argv[])
{
    int nlines, c;
    int reverse = 1, numeric = 0, fold = 0;

    while (--argc > 0 && *(*++argv) == '-')
    {
        while ((c = *++(*argv)) != '\0')
        {
            switch (c)
            {
            case 'n':
                numeric = 1;
                break;
            case 'r':
                reverse = -1;
                break;
            case 'f':
                fold = 1;
                break;
            default:
                break;
            }
        }
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        my_qsort((void **)lineptr, 0, nlines - 1, reverse,
                 (int (*)(void *, void *))(numeric ? numcmp : (fold ? strcmpignore : strcmp)));
        write_lines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("input to big to sort\n");
        return 1;
    }
}

/* my_qsort: sort v[left] ... v[right] into increasing order */
void my_qsort(void *v[], int left, int right, int reverse,
              int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) * reverse < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    my_qsort(v, left, last - 1, reverse, comp);
    my_qsort(v, last + 1, right, reverse, comp);
}

/* numcp: compare s1 and s2 numerically */
int numcmp(const char *s1, const char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

/* strcmpignore: compare S1 and s2*/
int strcmpignore(const char *s1,const  char *s2)
{
    for (; tolower(*s1) == tolower(*s2); ++s1, ++s2)
        if (*s1 == '\0')
            return 0;
    return tolower(*s1) - tolower(*s2);
}

/* swap: interchange v[i] and v[j] */
void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

#define MAXLEN 1000 /* max length of any input line */

int get_line(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
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

/* writeline: write output lines */
void write_lines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", lineptr[nlines]);
}

/* get_line: get line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* stroage for alloc */
static char *allocp = allocbuf;  /* next free position */

char *alloc(int n) /* return pointer to n character */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) /* it fits */
    {
        allocp += n;
        return allocp - n; /* old p */
    }
    else /* not enough room */
        return 0;
}
