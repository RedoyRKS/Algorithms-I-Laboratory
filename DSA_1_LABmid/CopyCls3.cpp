#include <stdio.h>
void menu();
void printList(struct List *temp);
int listSize(struct List *temp);

struct List
{
    int data;
    struct List *next;
};
typedef struct List node;

int main()
{
    int ch, n;
    node *head = NULL, *temp, *newNode;
    menu();
    scanf("%d", &ch);

    while (ch)
    {
        if (ch == 1)
        {
            if (head == NULL)
            {
                head = new node();
                printf("enter data: ");
                scanf("%d", &head->data);
                head->next = NULL;
            }
            else
            {
                newNode = new node();
                printf("enter data: ");
                scanf("%d", &newNode->data);
                newNode->next = head;
                head = newNode;
            }
        }
        else if (ch == 2)
        {
            printf("Enter position : ");
            scanf("%d", &n);
            if (n == 1)
            {
                if (head == NULL)
                {
                    head = new node();
                    printf("enter data: ");
                    scanf("%d", &head->data);
                    head->next = NULL;
                }
                else
                {
                    newNode = new node();
                    printf("enter data: ");
                    scanf("%d", &newNode->data);
                    newNode->next = head;
                    head = newNode;
                }
            }
            else
            {
                if (n >= 2 && n <= listSize(head) + 1)
                {
                    temp = head;
                    for (int i = 1; i <= n - 2; i++)
                    {

                        temp = temp->next;
                    }
                    newNode = new node();
                    printf("enter data: ");
                    scanf("%d", &newNode->data);
                    newNode->next = temp->next;
                    temp->next = newNode;
                }
                else
                {
                    printf("Invalid position\n");
                }
            }
        }
        else if (ch == 3)
        {
            if (head == NULL)
            {
                head = new node();
                printf("enter data: ");
                scanf("%d", &head->data);
                head->next = NULL;
            }
            else
            {
                temp = head;

                while (temp->next != NULL)
                {
                    temp = temp->next;
                }

                newNode = new node();
                printf("enter data: ");
                scanf("%d", &newNode->data);
                newNode->next = NULL;
                temp->next = newNode;
            }
        }
        else if (ch == 9)
        {
            printList(head);
        }
        else
        {
            printf("invalid choice. please try again...\n\n");
        }
        menu();
        scanf("%d", &ch);
    }

    return 0;
}

void menu()
{
    printf("1. Insert (head)\n");
    printf("2. Insert (nth position)\n");
    printf("3. Insert (tail)\n");
    printf("9. Print List\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

void printList(node *temp)
{
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

int listSize(node *temp)
{
    int i = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    return i;
}