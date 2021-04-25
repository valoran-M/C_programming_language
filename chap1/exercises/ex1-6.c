#include <stdio.h>

/*
Verify that the expression getchar() != EOF is 0 or 1
*/
void main()
{
    int c;
    while (c = getchar() != EOF)
        printf("%d \n", c);
    printf("%d - at EOF\n", c);
}
