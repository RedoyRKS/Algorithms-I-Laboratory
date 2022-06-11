#include<stdio.h>
void menu()
{
    printf("\t1.Push\n");
    printf("\t2.POP\n");
    printf("\t3.TOP\n");
    printf("\t4.Size\n");
    printf("\t0.Exit\n");
    printf("Enter your choice : ");
}
void Push(int arr[],int n,int top)
{
    printf("\t\t\tEnter the value to push :");
    scanf("%d",&arr[top]);
    //scanf("%d",&arr[top]);

}
void Pop(int arr[],int n,int top)
{
    printf("\t\t\t%d popped\n",arr[top]);
}
void Top(int arr[],int top)
{
    if(top > 0)
    {
        printf("\t\t\tTOP value : %d\n",arr[top-1]);
    }
    else
    {
        printf("\t\t\tStack is empty.\n");
    }
}
int Size(int top)
{
    return top;
}
int main()
{
    //stacks
    int data[100],n,ch,top = 0;
    printf("Enter size : ");
    scanf("%d",&n);
    menu();
    scanf("%d",&ch);
    while(ch)
    {
        if(ch==1)                //push
        {
            if(top==n)
            {
                printf("Stack is full. unable to push\n");
            }
            else
            {
                Push(data,n,top);
                top++;
            }
        }
        else if(ch==2)  //pop
        {
            if(top <= 0)
            {
                printf("\t\t\tStack is empty. Unable to pop\n");
            }
            else
            {
                --top;
                Pop(data,n,top);
            }
        }
        else if(ch==3)  //top
        {
            Top(data,top);
        }
        else if(ch == 4)   //size
        {
            printf("\t\t\tSize  : %d\n",Size(top));
        }
        else
        {
            printf("\t\t\tInvalid choice,try again\n");
        }
        menu();
        scanf("%d",&ch);
    }
    return 0;
}