/**
 * 
 * Chapter 5.5:
 * 
 *  Write a versions of the library function `strncpy`,
 * `strncat`, and `strncmp`, which operate on at most
 * the first n characters of thier argument strings.
 * For example, strncpy(s,t,n) copies at most n 
 * characters of t to s.
 * 
 **/

#include <stdio.h>
#include <string.h>

void my_strncpy(char *s, char *t, int n)
{
    while ((*s++ = *t++) && --n)
        ;
}

void my_strncat(char *s, char *t, int n)
{
    int size_s = strlen(s);
    s += size_s;

    while ((*s++ = *t++) && --n)
        ;
    *s = '\0';
}

int my_strncmp(char *s, char *t, int n)
{
    while ((*s++ == *t++) != '\0' && --n)
        if (*s == '\0')
            return 0;

    return *s - *t;
}

int main()
{
    char s1[] = "abcde";
    char t1[] = "xxxx";

    my_strncpy(s1, t1, 3);
    printf("%s\n", s1);

    char s2[] = "abcde";
    char t2[] = "fghijklm";

    my_strncat(s2, t2, 4);
    printf("%s\n", s2);

    printf("%d\n", my_strncmp(s2, t2, 5));
    printf("%d\n", my_strncmp(t2, s2, 5));

    return 0;
}