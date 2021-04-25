#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

/* Convert fahr to Celsius*/
void main()
{
    float fahr;

    printf("+--------------+\n");
    printf("|  F  |    C   |\n");
    printf("|-----|--------|\n");

    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
        printf("| %3.0f | %6.1f |\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
    printf("+--------------+\n");
}
