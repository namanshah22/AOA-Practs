#include <stdio.h>
#include <string.h>

#define d 256

// Function to search for a pattern within a text
void search(char pat[], char txt[], int q)
{
    int M = strlen(pat); // Length of the pattern
    int N = strlen(txt); // Length of the text
    int i, j;
    int p = 0; // Hash value for the pattern
    int t = 0; // Hash value for the current window
    int h = 1;

    // Calculate the value of h as (d^(M-1)) % q
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // Calculate the initial hash values for the pattern and the first window of the text
    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q; // Calculate the hash value for the pattern
        t = (d * t + txt[i]) % q; // Calculate the hash value for the current window
    }

    // Slide the pattern over the text one by one and check for a match
    for (i = 0; i <= N - M; i++)
    {
        // If the hash values of the pattern and the current window match, compare the pattern and the window
        if (p == t)
        {
            // Check if each character of the pattern matches the corresponding character in the window
            for (j = 0; j < M; j++)
            {
                if (txt[i + j] != pat[j])
                    break;
            }

            // If all characters match, the pattern is found at index i
            if (j == M)
                printf("Pattern found at index %d\n", i);
        }

        // Calculate the hash value for the next window by removing the leftmost character and adding the rightmost character
        if (i < N - M)
        {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}

int main()
{
    char txt[100], pat[100];

    // Read the text and pattern from the user
    printf("Enter the text: ");
    scanf("%s", txt);
    printf("Enter the pattern to match: ");
    scanf("%s", pat);

    int q = 101; // A prime number used for hashing

    // Call the search function to find the pattern in the text
    search(pat, txt, q);

    return 0;
}
