#include <stdio.h>

/* strcpy: copy t to s; array subscrpit */
void strcpyA(char *s, char *t)
{
    int i;

    i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}

void strcpyP(char *s, char *t)
{
    while (*s++ = *t++)
        ;
}

int main()
{

    char t[] = "hello\n";
    char s[100];
    strcpyP(s, t);
    printf("%s\n%s\n", t, s);
    return 0;
}