/**
 * Exercice 1.15
 * 
 *  Rewrite the temperature converion porgram to use
 * dunction for conversion
 * 
 **/

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float convert(float fahr);

void main()
{
    float fahr;

    printf("+--------------+\n");
    printf("|  F  |    C   |\n");
    printf("|-----|--------|\n");

    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
        printf("| %3.0f | %6.1f |\n", fahr, convert(fahr));
    printf("+--------------+\n");
}

float convert(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}