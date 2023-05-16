#include <stdio.h>
#include <stdbool.h>
int num_vertices, num_edges, num_colors;
int graph[100][100];
int colors[100];
bool used_colors[100];
int get_available_color(int vertex, int num_colors)
{
    for (int i = 0; i < num_colors; i++)
        used_colors[i] = false;
    for (int i = 0; i < num_vertices; i++)
    {
        if (graph[vertex][i] && colors[i] != -1)
            used_colors[colors[i]] = true;
    }
    for (int i = 0; i < num_colors; i++)
    {
        if (!used_colors[i])
            return i;
    }
    return -1;
}
void main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);
    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);
    for (int i = 0; i < num_vertices; i++)
    {
        colors[i]=-1;
        for (int j = 0; j < num_vertices; j++)
        {
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < num_edges; i++)
    {
        int u, v;
        printf("Enter edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    /*for (int i = 0; i < num_vertices; i++)
    {
        colors[i] = -1;
    }*/
    colors[0] = 0;
    for (int i = 1; i < num_vertices; i++)
    {
        colors[i] = get_available_color(i, num_colors);
    }
    printf("Coloring:\n");
    for (int i = 0; i < num_vertices; i++)
    {
        printf("Vertex %d: color %d\n", i, colors[i]);
    }
}