#include <stdio.h>

int v[100], w[] = {2, 3, 5, 6, 8, 10}, m = 10, n;

// Function to generate subsets with sum equal to m
void sos(int s, int k, int r)
{
    v[k] = 1; // Include the current element in the subset

    // If the sum of the subset equals m, print the subset
    if (s + w[k] == m)
    {
        printf("\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d\t", v[i]);
        }
    }
    // If including the current element and the next element still satisfies the sum condition, continue with recursion
    else if (s + w[k] + w[k + 1] <= m)
    {
        sos(s + w[k], k + 1, r - w[k]);
    }

    // If excluding the current element and including the next element satisfies the sum condition, continue with recursion
    if (s + r - w[k] >= m && s + w[k + 1] <= m)
    {
        v[k] = 0; // Exclude the current element from the subset
        sos(s, k + 1, r - w[k]);
    }
}

int main()
{
    n = 6; // Size of the array w[]

    int r = 0, i;
    for (i = 0; i < n; i++)
    {
        r += w[i]; // Calculate the sum of all elements in the array w[]
    }

    printf("Subsets:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", w[i]); // Print the elements of the array w[]
    }

    sos(0, 0, r); // Call the sos() function to generate subsets

    return 0;
}
