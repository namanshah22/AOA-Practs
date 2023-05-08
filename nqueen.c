#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool inPlace(int solution[], int k, int j){
    int i;
    for (i=0; i<k; i++) 
    {
        if ((solution[i]==j) || abs(solution[i] - j) == abs(k-i))
            return false;
    }
    return true;
}

void nQueens(int solution[], int k, int n){
    int i;
    static int count=0; 
    for (i=0; i<n; i++) 
    {
        if (inPlace(solution, k, i)) 
        {
            solution[k] = i; 
            if (k==n-1) 
            {
                count++;
                printf("Solution %d\n", count);
                for (int ct =0; ct <n; ct++)
                    printf("Queen %d placed in %d column\n",ct,solution[ct]);
                printf("\n");    
            }
            else
                nQueens(solution, k+1, n); 
        }
    }
}

int main() {
    int n;
    printf("Enter the number of Queens on n x n board (value of n) : ");
    scanf("%d",&n);
    int solution[30]; 
    int k=0;
    nQueens(solution, k, n);
}