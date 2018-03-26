#include<stdio.h>

int count( int S[], int m, int n ){
    if (n == 0) return 1;
    if (n < 0 || (m <=0 && n >= 1)) return 0;
    int without_last=count( S, m - 1, n );
    int with_last = count( S, m, n-S[m-1] );
    return without_last+with_last;
}
int main(){
    int i, j;
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    printf("%d ", count(arr, m, 4));
    return 0;
}
