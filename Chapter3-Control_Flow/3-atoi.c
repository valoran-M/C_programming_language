#include <stdio.h>
#include <ctype.h>

int atoi(char s[]);

int main()
{
    char s1[] = "123456  ";
    char s2[] = "-123456  ";
    char s3[] = "   123456 ";
    printf("%d\n", atoi(s1));
    printf("%d\n", atoi(s2));
    printf("%d\n", atoi(s3));
    return 0;
}

/* atoi: convert s to integer; version 2 */
int atoi(char s[])
{
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+'  || s[i] == '-') /* skip sign */
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}