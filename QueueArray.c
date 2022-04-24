#include<stdio.h>

void menu();

int main()
{
    int data[100], n, ch, head = 0, tail = 0, q_size = 0;

    printf("enter queue size: ");
    scanf("%d",&n);

    menu();
    scanf("%d",&ch);

    while(ch)
    {
        if(ch == 1)
        {
            //enqueue
            if(q_size == n)
            {
                printf("queue is full. unable to enqueue.\n\n");
            }
            else
            {
                printf("enter value to enqueue: ");
                scanf("%d",&data[tail]);
                tail = (tail + 1) % n;
                q_size++;
            }
        }
        else if(ch == 2)
        {
            //dequeue
            if(q_size == 0)
            {
                printf("queue is empty. unable to dequeue.\n\n");
            }
            else
            {
                printf("%d dequeued\n\n",data[head]);
                head = (head + 1) % n;
                q_size--;
            }

        }
        else if(ch == 3)
        {
            //top value
            if(q_size > 0)
            {
                printf("next value to dequeue: %d\n\n",data[head]);
            }
            else
            {
                printf("queue is empty\n\n");
            }

        }
        else if(ch == 4)
        {
            //size
            printf("queue size: %d\n\n",q_size);
        }
        else
        {
            printf("invalid choice. please try again!!!\n");
        }
        menu();
        scanf("%d",&ch);
    }



    return 0;
}

void menu()
{
    printf("1. enqueue\n");
    printf("2. dequeue\n");
    printf("3. top\n");
    printf("4. size\n");
    printf("0. exit\n");
    printf("enter your choice: ");
}
