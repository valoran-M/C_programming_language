#include <stdio.h>

/* Counitng char */
void main()
{
    long nc;
    for (nc = 0; getchar() != EOF; nc++)
        ;
    printf("%ld\n", nc);
}
