#include <stdio.h>

#define MAXLINE 1000

int my_getline(char line[], int maxline);
int lower(char c);

/* Print longest inout line */
void main()
{
    int len;               /* current line length */
    char line[MAXLINE];    /* current input line */

    len = my_getline(line, MAXLINE);
    for(int i = 0; i < len; i++)
        printf("%c", lower(line[i]));
}

/*lower: convert c to lower case; ASCII only */
int lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else 
        return c;
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