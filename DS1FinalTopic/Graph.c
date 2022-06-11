#include <stdio.h>
// in a tree there will be no loop,direction and multiple edges
// all trees are graph but all graphs are not tree
/*void Visit(int g[100][100], int visited[], int n)
void Visit(int g[100][100], int visited[], int n)
{
    printf("%c visited \n", 65 + n);
    visited[n] = 1;
}
void dfs(int g[100][100], int visited[], int k, int n)
{
    int i;
    Visit(g, visited, k);
    for (i = 0; i < n; i++)
    {
        if (g[k][i] == 1 && visited[i] == 0)
            dfs(g, visited, i, n);
    }
}
*/

int main()
{
    int n, i, j, visited[100];
    printf("Enter number of Vertices : ");
    scanf("%d", &n);
    int arr[n+1][n+1];
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            printf("Is there any edge between %c & %c ? ", 65 + i, 65 + j);
            scanf("%d", &arr[i][j]);
            arr[j][i] = arr[i][j];
        }
    }
    printf("Graph :\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
   // dfs(arr, visited, 0, n);
    dfs(arr, visited, 0, n);

    return 0;