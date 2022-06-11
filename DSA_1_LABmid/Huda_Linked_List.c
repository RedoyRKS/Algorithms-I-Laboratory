#include<stdio.h>
struct List
{
    int data;
    struct List *next;      
};

typedef struct List node;


int main(){
    int i,n;
    node *start, *prev, *temp;
    printf("How many node: ");
    scanf("%d",&n);
    start = (node*) malloc (sizeof(node));
    scanf("%d",&start->data);
    start->next = NULL;
    prev = start;
    for ( i = 2; i <=n ; i++)
    {
        temp = (node*) malloc (sizeof(node));
        scanf("%d",&temp->data);
        temp->next = NULL;
        prev->next = temp;
        prev = temp;
    }

    return 0;
    
}
void printList(node *start)
{
    node *temp;
    temp = start;

    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}