/* 
#include<stdio.h>
int main()

{       // Array string in find minimum number. Input won 
    int num[100],i, n;
    printf("How many numbers : ");
    scanf("%d", &n);
    printf("Push the value : ");

    for (i=0; i<n; i++)
    {
        scanf("%d",&num[i]);
    }
    int min = num[0];
    for(i=1; i<n; i++)
    {
        if(min > num[i])
           min = num[i];
    }
    printf("Minimum = %d\n",min);

}
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printArray(int data[], int n);


int main()
{
    int data[100],n,i;
    int min = data[0];

    printf("Enter the number : ");
    scanf("%d",&n);

    srand(time(NULL));
    for (i=0; i<n ; i++)
    {
        data[i]=rand()%100 + 1;   
    }
    for(i=1; i<n ;i++)
        {
            if (data[i] < min)
            min=data[i];
        }
        
    printf("The number :");
    printArray(data, n);
    printf("The minimum number is = %d\n",min);

   
}

void printArray(int data[], int n)
{
    int i;
    for (i=0; i<n ;i++)
    {
        printf("%d ",data[i]);
    }
    printf("\n");
}
