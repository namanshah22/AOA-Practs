#include <stdio.h>
#include <string.h>

void compute_prefix_function(char* p, int m, int* pi) {
    int k = 0;
    pi[0] = 0;
    for (int q = 1; q < m; q++) {
        while (k > 0 && p[k] != p[q]) {
            k = pi[k-1];
        }
        if (p[k] == p[q]) {
            k++;
        }
        pi[q] = k;
    }
}

void kmp_matcher(char* T, char* p) {
    int n = strlen(T);
    int m = strlen(p);
    int pi[m];
    compute_prefix_function(p, m, pi);
    int q = 0;
    int matches = 0;
    for (int i = 0; i < n; i++) {
        while (q > 0 && p[q] != T[i]) {
            q = pi[q-1];
        }
        if (p[q] == T[i]) {
            q++;
        }
        if (q == m) {
            printf("Pattern occurs with shift %d\n", i-m+1);
            matches++;
            q = pi[q-1];
        }
    }
    if (matches == 0) {
        printf("No matches found.\n");
    }
}

int main() {
    char T[100];
    char p[100];
    printf("Enter the text: ");
    scanf("%s", T);
    printf("Enter the pattern: ");
    scanf("%s", p);
    kmp_matcher(T, p);
    return 0;
}
