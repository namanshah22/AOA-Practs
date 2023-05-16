#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void main()
{
    int i, min,temp, n, j, a[50000];
    float s, e, t;
    printf("enter number of elements");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        a[i] = rand();
    }
    s = clock();
    for (i = 0; i < n-1; i++)
    {
        min = i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            //swap(a[j]anda[min])
            temp=a[j];
            a[j]=a[min];
            a[min]=temp;
        }
    }
        /*while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }*/
    e = clock();
    t = (float)(e - s);
    printf("It took %f seconds to execute \n", t);
}