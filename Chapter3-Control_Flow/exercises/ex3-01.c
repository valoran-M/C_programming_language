/**
 * Exercice 3.1
 * 
 *  Our binaray search makes two tests inside loop,
 * when one would suffice (at the price of more tests outside).
 * Write a version with only one test inside the loop and measure 
 * the difference in run-time
 * 
 **/

#include <stdio.h>

int binsearch(int x, int v[], int n);

void main()
{
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 11; i++)
        printf("%d\n", binsearch(i, v, 10));
}

/* binsearch: find c in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else /* found match */
            return mid;
    }
    return -1; /* no match */
}