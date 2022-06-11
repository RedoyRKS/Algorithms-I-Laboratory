#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printArray(int data[], int n);
void selectionSort(int data[], int n);
void bubbleSort(int data[], int n);
void insertionSort(int data[], int n);
int linearSearch(int data[], int n, int sv);
int binarySearch(int data[], int n, int sv);
int binarySearchRec(int data[], int lo, int hi, int sv);

int main()
{
    //printf("hello");
    int data[1000], n, i, sv;

    printf("enter array size: ");
    scanf("%d",&n);

    srand(time(NULL));
    for(i = 0; i < n; i++)
    {
        //scanf("%d",&data[i]);
        data[i] = rand()%100 + 1;// 1-100
    }

    printf("before sorting: ");
    printArray(data, n);

    //TODO
    //selectionSort(data, n);
    //bubbleSort(data, n);//124750
    //insertionSort(data, n);

//    printf("after sorting: ");
//    printArray(data, n);

    printf("enter value to search: ");
    scanf("%d",&sv);

    //linearSearch()<n ? printf("found\n") : printf("not found\n");

//    if(linearSearch(data, n, sv) < n)
//        printf("found\n");
//    else
//        printf("not found\n");

    bubbleSort(data, n);
    if(binarySearch(data, n, sv))
        printf("found\n");
    else
        printf("not found");



    return 0;
}

void printArray(int data[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ",data[i]);
    }
    printf("\n");
}





void insertionSort(int data[], int n)
{
    int i, j, key;
    for(i = 1; i < n; i++)
    {
        key = data[i];
        j = i - 1;

        while(j >= 0 && data[j] > key)
        {
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = key;
    }
}


void selectionSort(int data[], int n)
{
    int i, j, temp, min_index;

    for(i=0; i<n-1; i++)
    {
        min_index = i;
        for(j=i; j<n; j++)
        {
            if(data[min_index] > data[j])
            {
                min_index = j;
            }
        }
        temp = data[min_index];
        data[min_index] = data[i];
        data[i] = temp;
    }
}

void bubbleSort(int data[], int n)
{
    int i, j, temp;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            if(data[j] > data[j+1])
            {
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}

int linearSearch(int data[], int n, int sv)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(data[i] == sv)
            return i;
    }
    return i;
}

int binarySearch(int data[], int n, int sv)
{
    int lo = 0, hi = n-1, mid;
    while(lo <= hi)
    {
        mid = (lo + hi)/2;
        if(data[mid] == sv) return 1;
        else if(data[mid] < sv) lo = mid + 1;
        else hi = mid - 1;
    }
    return 0;
}



