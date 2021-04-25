#include <stdio.h>

/*
Program which counitng char
*/
void main()
{
    long nc;
    for (nc = 0; getchar() != EOF; nc++)
        ;
    printf("%ld\n", nc);
}
