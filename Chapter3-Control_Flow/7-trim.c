#include <stdio.h>
#include <string.h>

int trim(char s[]);

void main()
{
    char s[] = "lfkjqhdfkjq\t";
    trim(s);
    printf("%c\n", s[strlen(s) - 1]);
}

int trim(char s[])
{
    int n;

    for (n = strlen(s) - 1; n >= 0; n--)
        if (s[n] != '\n' && s[n] != '\t' && s[n] != ' ')
            break;

    s[n+ 1] = '\0';
    return n;
}