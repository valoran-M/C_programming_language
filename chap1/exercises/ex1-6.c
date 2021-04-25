/**
 * Exercice 1.6
 * 
 *  Verify that the expression getchar() != EOF is 0 or 1
 * 
 **/

#include <stdio.h>

void main()
{
    int c;
    while (c = getchar() != EOF)
        printf("%d \n", c);
    printf("%d - at EOF\n", c);
}
