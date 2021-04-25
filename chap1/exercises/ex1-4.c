#include <stdio.h>

/*
Write a program to print 
the corresponding Celsius to Fahrenheit
*/
void main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("+------------+\n");
    printf("| C  |   F   |\n");
    printf("|----|-------|\n");

    celsius = lower;
    while (celsius <= upper)
    {
        fahr = celsius / (5.0 / 9.0) + 32.0;
        printf("|%3.0f | %6.1f|\n", celsius, fahr);
        celsius += step;
    }
    printf("+------------+\n");
}
