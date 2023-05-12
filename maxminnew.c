#include<stdio.h>
#include<stdlib.h>
//#define n 5
int max,min,a[10],n;
void maxmin(int a[],int low,int high)
{
    int max1,min1,mid;
    if(low==high)
    {
    max=min=a[low];
    }
    else if(low==high-1)
    {
        if(a[low]<a[high])
        {
            min=a[low];
            max=a[high];
        }
        else
        {
            min=a[high];
            max=a[low];
        }
    }
    else
    {
        mid=(low+high)/2;
        maxmin(a,low,mid);
        max1=max;
        min1=min;
        maxmin(a,mid+1,high);
        if(max1>max)
            max=max1;
        if(min1<min)
            min=min1;
    }
}
void main()
{
    int i,n,a[10];
    printf("Enter the number of elements:");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        printf("Enter element %d:",i+1);
        scanf("%d",&a[i]);
    }
    max=a[0];
    min=a[0];
    maxmin(a,0,n-1);
    printf("\nMax is %d\nMin is %d",max,min);
}