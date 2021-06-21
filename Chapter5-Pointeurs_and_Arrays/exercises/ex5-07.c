/**
 * Exercice 5.7:
 * 
 *  Rewrite readlines to store lines in an array 
 * supplied by main, rather than calling alloc to 
 * maintain storage. How much faster is the 
 * progtam?
 * 
 **/

#include <stdio.h>
#include <string.h>

#define MAXLINE 5000
#define ALLOCSIZE 10000

char *lineptr[MAXLINE];

int readlines(char *lineptr[], char *, int nlines);
void writeline(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main()
{
    int nlines;
    char allocbuf[ALLOCSIZE];

    if ((nlines = readlines(lineptr, allocbuf, MAXLINE)) >= 0)
    {
        qsort(lineptr, 0, nlines - 1);
        writeline(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000 /* max length of any input line */
int get_line(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], char *allocbuf, int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    p = allocbuf;
    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (ALLOCSIZE + allocbuf - p < len))
            return -1;
        else
        {
            line[len - 1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    return nlines;
}

/* writeline: write output lines */
void writeline(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", lineptr[nlines]);
}

/* qsort: sort v[left] ... v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) > 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
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