#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int findMinDiff(int arr[], int n, int m)
{
    if (m==0 || n==0)
        return 0;

    sort(arr, arr+n);
    if (n < m)
       return -1;
    int min_diff = INT_MAX;
    int first = 0, last = 0;
    for (int i=0; i+m-1<n; i++)
    {
        int diff = arr[i+m-1] - arr[i];
        if (diff < min_diff)
        {
            min_diff = diff;
            first = i;
            last = i + m - 1;
        }
    }
    return (arr[last] - arr[first]);
}

int main()
{
    int arr[] = {12, 4, 7, 9, 2, 23, 25, 41,
                 30, 40, 28, 42, 30, 44, 48,
                 43, 50};
    int m = 7;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Minimum difference is "
         << findMinDiff(arr, n, m);
    return 0;
}
