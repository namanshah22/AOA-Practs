#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000
#define MAX_EDGES 1000

int parent[MAX_NODES];
int rank[MAX_NODES];

void makeSet(int n) {
    for(int i=0; i<n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find(int x) {
    if(parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void merge(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if(rootX == rootY) {
        return;
    }

    if(rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootX] = rootY;
        if(rank[rootX] == rank[rootY]) {
            rank[rootY]++;
        }
    }
}

void kruskal(int n, int m, int edges[][3]) {
    int i = 0, j = 0;
    int numEdges = 0;
    int treeWeight = 0;

    makeSet(n);

    while(numEdges < n-1) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        if(find(u) != find(v)) {
            merge(u, v);
            numEdges++;
            treeWeight += w;
            printf("Added edge %d-%d with weight %d to the tree.\n", u, v, w);
        }
        i++;
    }

    printf("The total weight of the minimum spanning tree is %d.\n", treeWeight);
}

int main() {
    int n, m;
    int edges[MAX_EDGES][3];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the source vertex, destination vertex, and weight of each edge:\n");
    for(int i=0; i<m; i++) {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    printf("Running Kruskal's algorithm...\n");
    kruskal(n, m, edges);

    return 0;
}
