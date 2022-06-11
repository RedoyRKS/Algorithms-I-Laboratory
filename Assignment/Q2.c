#include<stdio.h>
#include<stdlib.h>
int main()
{
    int N, x[1000], y[100];
    printf("Enter the number : ");
    scanf("%d", &N);
    for(int i=0; i<100; i++)
    {
        y[i]=0;
    }
    for(int i=0; i<N; i++)
    {
        x[i]=rand()%100+1;
    }
    for (int  i = 0; i < N; i++)
    {
        y[x[i]]++;
    }
    int max = y[0], k;
    for (int i = 1; i < 100; i++)
    {
        if (y[i]>max)
        {
            max=y[i];
        }
    }
    int count = 0 ;
    for (int i = 0; i < 100; i++)
    {
        if (max==y[i])
        {
            count++;
        }   
    }
    for (int i = 0; i < 100; i++)
    {
        if (max==y[i])
        {
            if (count>1)
            {
                printf("%d, ", i);
                count--;
            }
            else
            {
                k=i;
            }
             
        }
        
    }
    printf("%d ",k);
    printf("occured %d times.",y[k]);


    return 0;  
    
}