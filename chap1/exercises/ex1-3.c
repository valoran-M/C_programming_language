#include <stdio.h>

/* Modify the temperature conversion program to
print heading above the table*/
void main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("+------------+\n");
    printf("| F  |   C   |\n");
    printf("|----|-------|\n");

    fahr = lower;
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("|%3.0f | %6.1f|\n", fahr, celsius);
        fahr += step;
    }
    printf("+------------+\n");

}
