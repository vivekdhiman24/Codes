#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    int i;
    for (i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void rearrangeUtil(int arr[], int n, int i)
{
    int val = -(i+1);
    i = arr[i] - 1;

    while (arr[i] > 0)
    {
        int new_i = arr[i] - 1;
        arr[i] = val;
        val = -(i + 1);
        i = new_i;
    }
}

void rearrange(int arr[], int n)
{
    int i;
    for (i=0; i<n; i++)
        arr[i]++;

    for (i=0; i<n; i++)
    {
       if (arr[i] > 0)
          rearrangeUtil(arr, n, i);
    }

    for (i=0; i<n; i++)
          arr[i] = (-arr[i]) - 1;
}


int main()
{
    int arr[] =  {2, 0, 1, 4, 5, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, n);

    rearrange(arr,  n);

    printf("Modified array is \n");
    printArray(arr, n);
    return 0;
}
