/**
 * Exercice 5.4:
 * 
 *  Write the function strend(s, t), which returns 1
 * if the string t occurs at the end of the string s,
 * and zero otherwise.
 * 
 **/

#include <stdio.h>
#include <string.h>

int strend(char *s, char *t);

int main()
{
    char s[] = "test";
    char t1[] = "test";
    char t2[] = "tests";

    if(strend(s, t1))
        printf("t1 - good\n");

    if(!strend(s, t2))
        printf("t2 - good\n");

    return 0;
}

int strend(char *s, char *t)
{
    int size_s = strlen(s);
    int size_t = strlen(t);

    s += size_s;
    t += size_t;

    while (size_t && (*s-- == *t--))
        --size_t;

    if (size_t)
        return 0;

    return 1;
}