// A naive C/C++ based recursive implementation of LIS problem
#include<stdio.h>
#include<stdlib.h>

// Recursive implementation for calculating the LIS
int lis(int arr[], int n, int *max_lis_length)
{
	// Base case
	if (n == 1)
		return 1;

	int current_lis_length = 1;
	for (int i=0; i<n-1; i++)
	{
		printf(" %d->%d\n",i,n-1);
		int subproblem_lis_length = lis(arr, i, max_lis_length);


		if (arr[i] < arr[n-1] &&
			current_lis_length < (1+subproblem_lis_length))
			current_lis_length = 1+subproblem_lis_length;
	}

	if (*max_lis_length < current_lis_length)
		*max_lis_length = current_lis_length;

	return current_lis_length;
}

int lisDP( int arr[], int n )
{
    int *lisTable, i, j, max = 0;
    int max_lis=1;

    lisTable = (int*) malloc ( sizeof( int ) * n );

    for (i = 0; i < n; i++ )
        lisTable[i] = 1;

    for (i = 1; i < n; i++ ){
        for (j = 0; j < i; j++ ){
            printf("%d-%d\n",i,j);
            if ( arr[i] > arr[j] && lisTable[i] < lisTable[j] + 1){
                lisTable[i] = lisTable[j] + 1;
            	if(max_lis < lisTable[i]){
            		max_lis = lisTable[i];
            	}
            }
        }
    }
    return max_lis;
}

int main()
{
	int arr[] = {3,10,4,20};
	int arr1[]={3,10,4,20};
	int max_lis_length = 1;
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Length of LIS is %d\n", lis( arr, n, &max_lis_length));
	printf("-------- DP -----------");
	printf("Length of LISDP is %d\n", lisDP( arr1, n));
	return 0;
}
