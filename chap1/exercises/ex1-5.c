#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main(int argc, char const *argv[])
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("+--------------+\n");
    printf("|  F  |    C   |\n");
    printf("|-----|--------|\n");

    for (fahr = lower; fahr <= upper; fahr += step)
        printf("| %3.0f | %6.1f |\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
    printf("+--------------+\n");

    return 0;
}
