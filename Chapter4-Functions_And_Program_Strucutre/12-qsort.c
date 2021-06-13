#include <stdio.h>

void qsort(int v[], int left, int right);

int main()
{
    int i;
    int a[] = {1, 4, 2, 7, 0, 3, 9, 5, 6, 8};
    for (i = 0; i < 10; i++)
        printf("%d", a[i]);
    putchar('\n');
    qsort(a, 0, 9);

    for (i = 0; i < 10; i++)
        printf("%d", a[i]);
    putchar('\n');
}

void qsort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right)                 /* do nothing if array contains */
        return;                        /* fewer than two elements */
    swap(v, left, (left + right) / 2); /* move partition elem */
    last = left;                       /* to v[0] */
    for (i = left + 1; i <= right; i++)
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}