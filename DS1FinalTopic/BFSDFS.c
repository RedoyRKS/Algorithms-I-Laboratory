#include <stdio.h>
int f = 0, r = -1, q[100] = {};
void dfs(int g[100][100], int visited[], int source, int n) // n: number of vertices, k: node
{
    int i;
    visited[source] = 1;
    printf("%c visited\n", 65 + source);
    for (i = 0; i < n; i++)
    {
        if (g[source][i] == 1 && visited[i] == 0)
            dfs(g, visited, i, n);
    }
}
void bfs(int g[100][100], int visited[], int source, int n)
{
    int i;
    for (i = 1; i <= n; i++)
        if (g[source][i] && !visited[i])
            q[++r] = i;
    if (f <= r)
    {
        visited[q[f]] = 1;
        bfs(g, visited, q[++r], n);
    }
}
int main()
{
    int vertex, i, j;
    printf("Enter number of vertex: ");
    scanf("%d", &vertex);
    int arr[100][100], visited[100];
    for (i = 0; i < vertex; i++)
    {
        for (j = i + 1; j < vertex; j++)
        {
            printf("edge between %c & %c: ", 65 + i, 65 + j);
            scanf("%d", &arr[i][j]);
            arr[j][i] = arr[i][j];
        }
    }
    printf("Graph values: \n");
    for (i = 0; i < vertex; i++)
    {
        for (j = 0; j < vertex; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("DFS : \n");
    dfs(arr, visited, 0, vertex);
    bfs(arr, visited, 0, vertex);
    printf("\n BFS:\n");
    for (i = 0; i < vertex; i++)
        if (visited[i])
            printf("%c\t", 65 + i);
        else
            printf("\n Bfs is not possible\n");
    return 0;
}