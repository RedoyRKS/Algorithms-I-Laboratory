#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int val;
    struct node *next;  
}
node;

node* insert(node *head,int n)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->val = n;
    newNode->next= NULL;
    if (head==NULL)
    {
        head =newNode;
    }
    else
    {
        struct node *lastNode = head;
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
    return head;
}

node* customOrder(node *head)
{

    int list[100]={0};
    int count[100]={0};
    int point=0;
    node *ptr=head;
    while(head!=NULL)
    {
        int flag=0;
        for(int i=0;i<point;i++)
        {
            if(list[i]==head->val)
            {
                count[i]++;
                flag=1;
            }
        }
        if(flag==0)
        {
            list[point]=head->val;
            count[point++]=1;
        }
        head=head->next;
    }
    for(int i=0;i<point-1;i++)
    {
        for(int j=0;j<point-1;j++)
        {
            if(count[j]<count[j+1])
            {
                int temp=count[j];
                count[j]=count[j+1];
                count[j+1]=temp;
                temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
            }
        }
    }
    printf("New list: ");
    for(int i=0;i<point;i++)
    {
        for(int j=0;j<count[i];j++)
        {
            printf("%d ",list[i]);
        }
    }
    return head;
}

int main()
{
    int N,x;
    node *head=NULL;
    printf("\nEnter N: ");
    scanf("%d",&N);
    printf("\nOld list: ");
    for(int i=0;i<N;i++)
    {
        scanf("%d",&x);
        head=insert(head,x);
    }
    customOrder(head);

    return 0;
}
