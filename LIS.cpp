#include<stdio.h>
#include<stdlib.h>

void lis( int arr[], int n )
{
    int *lisTable, i, j, max = 0;
    int max_lis=1;

    lisTable = (int*) malloc ( sizeof( int ) * n );

    for (i = 0; i < n; i++ )
        lisTable[i] = 1;

    for (i = 1; i < n; i++ )
        for (j = 0; j < i; j++ )
            if ( arr[i] > arr[j] && lisTable[i] < lisTable[j] + 1){
                lisTable[i] = lisTable[j] + 1;
            	if(max_lis < lisTable[i]){
            		max_lis = lisTable[i];
            	}
            }

    /*for (i = 0; i < n; i++ )
        if (max < lisTable[i])
            max = lisTable[i];
    */
printf("Max_LIS %d \n",max_lis);
//printf("Max %d \n",max);
}
int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    lis( arr, n );

    int arr1[] = { 3, 10, 4, 1, 15, 20 };
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    lis( arr1, n1 );

    int arr2[] = { 3, 30, 4, 20, 1, 5 };
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    lis(arr2,n2);
    return 0;

}
