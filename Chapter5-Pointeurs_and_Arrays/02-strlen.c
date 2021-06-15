#include <stdio.h>

/* strlen: return length of string */
int str_len(char *s)
{
    int n;

    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
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
