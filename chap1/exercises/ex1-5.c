#include <stdio.h>

/*
Modify the temperature conversion program to
print the table in reverse order, that is, from 300 degrees to 0.
*/
void main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 300;
    upper = 0;
    step = -20;

    printf("+--------------+\n");
    printf("|  F  |    C   |\n");
    printf("|-----|--------|\n");

    for (fahr = lower; fahr >= upper; fahr += step)
        printf("| %3.0f | %6.1f |\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
    printf("+--------------+\n");
}
