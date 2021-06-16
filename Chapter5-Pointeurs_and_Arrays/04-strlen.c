#include <stdio.h>

/* strlen: return length of string */
int str_len(char *s)
{
    char *p = s;

    while (*p != '\0')
        p++;
    return p - s;
}

int main()
{
    char test1[] = "Hello\n";
    char test2[] = "";
    printf("%d\n", str_len("hellow, world"));
    printf("%d\n", str_len(test1));
    printf("%d\n", str_len(test2));

    return 0;
}
