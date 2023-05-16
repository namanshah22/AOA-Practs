#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void main()
{
    int i, key, n, j, a[50000];
    float s, e, t;
    printf("enter number of elements");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        a[i] = rand();
    }
    s = clock();
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
    e = clock();
    t = (float)(e - s);
    printf("It took %f seconds to execute \n", t);
}