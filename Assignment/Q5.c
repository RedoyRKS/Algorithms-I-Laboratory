#include<stdio.h>

double absolute(double value)
{

    if(value<0)
    {
        return -value;
    }

    else
    {
        return value;
    }

}

double cubeRoot(int N)
{

    double threshold=0.005;

    double l=0, h=N;
    double root=0, cube;

    int done=0;

    while(!done)
    {

        root = (l+h)/2.0;

        cube = root*root*root;

        if(absolute(cube-N)<threshold)
        {
            done=1;
        }

        else if(cube<N)
        {
            l=root;
        }

        else
        {
            h=root;
        }
    } 

    return root;
}
int main()
{
    int N;

    printf("Enter value for N: ");
    scanf("%d",&N);

    printf("Cube root: %.3f\n",cubeRoot(N));

    return 0;
}