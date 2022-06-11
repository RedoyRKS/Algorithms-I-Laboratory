#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int val;
    struct Node *next;
};
typedef struct Node node;


node* seperateOddEven(node *head, int direction);
void printList(struct Node* tmp);

struct Node* createNode();
struct Node* insert_tail(struct Node *head, struct Node *newnode);
struct Node* insert_head(struct Node *head, struct Node *newnode);



int main()
{
    int i = 0;
    int n;
    int m;
    node *head;
    head = NULL;
    node *newnode;
    printf("Enter N: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        printf("Input: ");
        scanf("%d",&n);
    }
    while(i<n)
    {
       newnode = createNode();
       head = insert_head(head, newnode);
       i = i+1;
    }
    
    printList(head);

    printf("\nInput either 1 : ");
    scanf("%d",&m);
    seperateOddEven(head, m);
    


}

node* createNode()
{
    node *tmp = new node();
    tmp->val = 
    tmp->next = NULL;
    return tmp;
}

node* insert_head(node *head, node *newnode)
{

    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }

    return head;
}



void printList(node* tmp)
{
    while(tmp != NULL)
    {
        printf("%d ",tmp->val);
        tmp = tmp->next;
    }

}
node* seperateOddEven(node *head, int direction)
{
    node *odd = NULL, *even = NULL , *tmp, *newnode;
    tmp = head;


    if(direction == 1)
    {
       while(tmp->val != NULL)
       {

           newnode = createNode();
           newnode->val = tmp->val;

           if(newnode->val%3 == 0)
           {

               even = insert_head(even, newnode);
           }
           else{

                odd = insert_head(odd, newnode);
           }
           if(tmp->next==NULL)
           {
               printList(odd);
               printList(even);
           }
           tmp = tmp->next;

       }
    }
    
    return head;
}

node* insert_tail(node *head, node *newnode)
{
    if(head == NULL)
    {
        head = insert_head(head, newnode);
    }
    else
    {
        node *tmp;
        tmp = head;
        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = newnode;
    }
    return head;
}

