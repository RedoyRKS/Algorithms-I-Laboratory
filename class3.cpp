#include<stdio.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

//Function prototypes
int selectOption();
node* createNode();
void printList(node *head);
node* insert_head(node *head, node *nn);
node* insert_tail(node *head, node *nn);
node* insert_nth(node *head, node *nn, int pos);


int node_count = 0;

int main()
{
    node *head = NULL, *nn;

    int ch, pos;
    ch = selectOption();

    while(ch)
    {
        if(ch == 1)
        {
            nn = createNode();
            head = insert_head(head, nn);
        }
        else if(ch == 2)
        {
            printf("enter position: ");
            scanf("%d",&pos);
            if(pos >= 1 && pos <= node_count + 1)
            {
                nn = createNode();
                head = insert_nth(head, nn, pos);
            }
            else
            {
                printf("invalid position.\n\n");
            }

        }
        else if(ch == 3)
        {
            nn = createNode();
            head = insert_tail(head, nn);
        }
        else if(ch == 8)
        {
            printf("list size: %d\n",node_count);
        }
        else if(ch == 9)
        {
            printList(head);
        }
        else
        {
            printf("invalid option. please try again...\n\n");
        }
        ch = selectOption();
    }
}

int selectOption()
{
    int ch;
    printf("1. insert (head)\n");
    printf("2. insert (nth)\n");
    printf("3. insert (tail)\n");
    printf("8. print list size\n");
    printf("9. print list\n");
    printf("0. exit\n\n");

    printf("enter your option: ");
    scanf("%d",&ch);
    return ch;
}

node* createNode()
{
    node *temp;
    temp = new node();
    temp->next = NULL;
    printf("enter value: ");
    scanf("%d",&temp->data);
    return temp;
}

void printList(node *head)
{
    node *temp;
    temp = head;

    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

node* insert_head(node *head, node *nn)
{
    if(head != NULL)
    {
        nn->next = head;
    }
    head = nn;
    node_count++;
    return head;
}

node* insert_tail(node *head, node *nn)
{
    if(head == NULL)
    {
        head = insert_head(head, nn);
    }
    else
    {
        node *temp;
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
        node_count++;
    }

    return head;
}

node* insert_nth(node *head, node *nn, int pos)
{
    if(pos == 1)
    {
        head = insert_head(head, nn);
    }
    else if(pos == node_count + 1)
    {
        head = insert_tail(head, nn);
    }
    else
    {
        node *temp;
        temp = head;
        int i;
        for(i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }
        nn->next = temp->next;
        temp->next = nn;
        node_count++;
    }

    return head;
}




