#include <stdio.h>

int selectOption();
int pop(int data[]);
void push(int data[], int v);
int getTopElement(int data[]);
int getStackSize();
void enqueue(int data[], int v);

int top = -1;

int main()
{
    int graph[100][100], data[100], n, ch, v, i, j;
    int visited[100];
    printf("Enter number of vertex: ");
    scanf("%d", &n);
    ch = selectOption();
    while (ch)
    {
        if (ch == 1)
        {
            for (i = 0; i < n; i++)
            {
                for (j = i + 1; j < n; j++)
                {
                    printf("Edge between %c and %c? ", 65 + i, 65 + j);
                    scanf("%d", &graph[i][j]);
                    graph[j][i] = graph[i][j];
                }
            }
        }
        else if (ch == 2)
        {
            int s;
            char c;
            printf("Enter source vertex: ");
            fflush(stdin);
            scanf("%c", &c);
            s = c - 65;

            // printf("s = %d\n",s);

            push(data, s);
            int vertex;
            while (getStackSize() != 0)
            {
                vertex = pop(data);
                if (visited[vertex] != 1)
                {
                    for (i = 0; i < n; i++)
                    {
                        if (graph[vertex][i] == 1)
                            push(data, i);
                    }
                    visited[vertex] = 1;
                    printf("%c visited\n", 65 + vertex);
                }
            }
        }
        else if (ch == 3)
        {
            // Implement BFS using Queue.
        }
        else if (ch == 4)
        {
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    printf("%d\t", graph[i][j]);
                }
                printf("\n");
            }
        }
        else
        {
            printf("Invalid choice. Please try again.\n\n");
        }
        ch = selectOption();
    }
}

int selectOption()
{
    printf("1. Create Graph\n");
    printf("2. DFS\n");
    printf("3. BFS\n");
    printf("4. Print Graph\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    int n;
    scanf("%d", &n);
    return n;
}

int getStackSize()
{
    return top + 1;
}

int getTopElement(int data[])
{
    return data[top];
}

void push(int data[], int v)
{
    top++;
    data[top] = v;
    // return top;
}

int pop(int data[])
{
    int temp = data[top];
    top--;
    return temp;
}
