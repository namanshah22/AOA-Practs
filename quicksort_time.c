#include <stdio.h>
#include<time.h>
void quicksort(int a[], int low, int high);
int partition(int a[], int low, int high);

int main() {
    int n, a[50000], i,x, choice;
    double start,end,diff;
    printf("Enter choice ");
    scanf("%d", &choice);
    switch (choice)
    {
    case '1': x=1;
        break;
    case '2': x=rand();
        break;
    case '3': x=n-1;
        break;
    default: printf("error");
        break;
    }
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    for(i=0; i<n; i++) {
        a[i]=x;
        
    }
    start=clock();
    quicksort(a, 0, n-1);
    end=clock();
    diff=((double)(end-start));
    printf("Time taken %f to run",diff);
    return 0;
}

int partition(int a[], int low, int high) {
    int i, j, temp, pivot;
    pivot = a[low];
    i = low;
    j = high;
    while(i < j) {
        do
        {
            i++;
        }while (a[i]<=pivot);
        do{
            j--;
        }while (a[j]>pivot );

        if(i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    a[low] = a[j];
    a[j] = pivot;
    return j;
}

void quicksort(int a[], int low, int high) {
    if(low < high) {
        int j = partition(a, low, high);
        quicksort(a, low, j-1);
        quicksort(a, j+1, high);
    }
}
