#include <stdio.h>

void main(int argc, char const *argv[])
{
    int c;
    while (c = getchar() != EOF)
        printf("%d \n", c);
    printf("%d - at EOF\n", c);
}
