#include <stdio.h>

void shellsort(int v[], int n);

int main()
{
    int v[] = {9, 3, 5, 0, 6, 8, 1, 2, 4, 7};
    shellsort(v, 10);
    for (int i = 0; i < 10; i++)
        printf("%d\n", v[i]);
}

/* shellsort: sort v[0] .. v[n -1] int increasing order */
void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
            {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
}