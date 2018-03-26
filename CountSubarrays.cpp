#include <iostream>
using namespace std;

int countSubarray(int arr[], int n, int k){
    int s = 0;
    int i = 0;
    while (i < n)
    {
        if (arr[i] > k){
            i++;
            continue;
        }
        int count = 0;
        while (i < n && arr[i] <= k)
        {
            i++;
            count++;
        }
        s += ((count*(count+1))/2);
    }

    return (n*(n+1)/2 - s);
}
int main()
{
    int arr[] = {1, 2, 3};
    int k = 2;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << countSubarray(arr, n, k);
    return 0;
}
