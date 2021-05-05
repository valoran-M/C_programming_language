#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

int my_getline(char line[], int maxline);
int atoi(char s[]);

/* Print longest inout line */
void main()
{
    int len;               /* current line length */
    char line[MAXLINE];    /* current input line */

    my_getline(line, MAXLINE);
    printf("%d\n", atoi(line));
}

/*atoi: convert s to integer */
int atoi(char s[])
{
    int i, n;

    n = 0;
    for(i = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return n;
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
    s[i] = '\0';
    return i;
}