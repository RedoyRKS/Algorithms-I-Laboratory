#include<stdio.h>
void menu();
void printList(struct List *temp);
int listSize(struct List *temp);

struct List
{
    int data;
    struct List *next;
    struct List *prev;
};
typedef struct List node;

node* insert_head(node *head)
{
    node *nn;
    nn = new node();
    nn->next = NULL;
    nn->prev = NULL;
    printf("enter data: ");
    scanf("%d",&nn->data);
    if(head != NULL)
    {
        nn->next = head;
        head->prev = nn;
    }
    head = nn;
    return head;
}

node* insert_tail(node *head)
{
    if(head == NULL)
    {
        head = insert_head(head);
    }
    else
    {
        node *temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        node *newNode = new node();
        printf("enter data: ");
        scanf("%d",&newNode->data);
        newNode->next = NULL;
        newNode->prev = temp;

        temp->next = newNode;

    }
    return head;
}

node* insert_at_N(node *head, int n)
{
    if(n == 1)
    {
        head = insert_head(head);
    }
    else
    {
        if(n >= 2 && n <= listSize(head)+1)
        {
            if(n == listSize(head)+1)
            {
                head = insert_tail(head);
            }
            else
            {
                node *temp;
                int i;
                temp = head;
                for(i = 1; i <= n-2; i++)
                {
                    temp = temp->next;
                }
                node *newNode = new node();
                printf("enter data: ");
                scanf("%d",&newNode->data);
                //newNode->next = NULL;

                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next = newNode;
                newNode->next->prev = newNode;
            }

        }
        else
        {
            printf("invalid position...\n\n");
        }
    }
    return head;
}

int main()
{
    int ch, n, i;
    node *head = NULL, *temp, *newNode;
    menu();
    scanf("%d",&ch);

    while(ch)
    {
        if(ch == 1)
        {
            head = insert_head(head);
        }
        else if(ch == 2)
        {
            printf("enter position: ");
            scanf("%d",&n);
            head = insert_at_N(head, n);
        }
        else if(ch == 3)
        {
            head = insert_tail(head);
        }
        else if(ch == 4)
        {
            if(head == NULL)
            {
                printf("list is empty.\n\n");
            }
            else
            {
                temp = head;
                head = head->next;
                head->prev = NULL;
                printf("%d deleted\n\n",temp->data);
                delete(temp);
            }
        }
        else if(ch == 5)
        {
            if(head == NULL)
            {
                printf("list is empty.\n\n");
            }
            else
            {
                printf("enter position: ");
                scanf("%d",&n);

                if(n > listSize(head) || n < 1)
                {
                    printf("invalid position\n\n");
                }
                else
                {
                    temp = head;
                    if(n == 1)
                    {

                        temp = head;
                        head = head->next;
                        head->prev = NULL;
                        printf("%d deleted\n\n",temp->data);
                        delete(temp);
                    }
                    else if(n == listSize(head))
                    {

                        temp = head;
                        if(head->next == NULL)
                        {
                            printf("%d deleted\n\n",temp->data);
                            delete(temp);
                            head = NULL;
                        }
                        else
                        {
                            while(temp->next->next != NULL)
                            {
                                temp = temp->next;
                            }
                            node *dl = temp->next;
                            printf("%d deleted\n\n",dl->data);
                            delete(dl);
                            temp->next = NULL;
                        }
                    }
                    else
                    {
                        for(i = 1; i <= n-1; i++)
                        {
                            temp = temp->next;
                        }
                        node *pr = temp->prev;
                        node *fw = temp->next;

                        pr->next = fw;
                        fw->prev = pr;
                        printf("%d deleted\n\n",temp->data);
                        delete(temp);
                    }
                }
            }
        }
        else if(ch == 6)
        {
            if(head == NULL)
            {
                printf("list is empty.\n\n");
            }
            else
            {
                temp = head;
                if(head->next == NULL)
                {
                    printf("%d deleted\n\n",temp->data);
                    delete(temp);
                    head = NULL;
                }
                else
                {
                    while(temp->next->next != NULL)
                    {
                        temp = temp->next;
                    }
                    node *dl = temp->next;
                    printf("%d deleted\n\n",dl->data);
                    delete(dl);
                    temp->next = NULL;
                }
            }
        }
        else if(ch == 9)
        {
            printList(head);
        }
        else
        {
            printf("invalid choice. please try again...\n\n");
        }
        menu();
        scanf("%d",&ch);
    }




    //printf("hello\n");
    return 0;
}

void menu()
{
    printf("1. Insert (head)\n");
    printf("2. Insert (nth position)\n");
    printf("3. Insert (tail)\n");
    printf("4. Delete (head)\n");
    printf("5. Delete (nth position)\n");
    printf("6. Delete (tail)\n");
    printf("9. Print List\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

void printList(node *temp)
{
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

int listSize(node *temp)
{
    int i = 0;
    while(temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    return i;
}
