#include <iostream>
#include <climits>
#include <cstdlib>
using namespace std;

void printClosest(int ar1[], int ar2[], int m, int n, int x)
{
    int diff = INT_MAX;

    int res_i, res_j;
    int i = 0, j = n-1;
    while (i<m && j>=0)
    {
       if (abs(ar1[i] + ar2[j] - x) < diff)
       {
           res_i = i;
           res_j = j;
           diff = abs(ar1[i] + ar2[j] - x);
       }

       if (ar1[i] + ar2[j] > x)
           j--;
       else
           i++;
    }

    cout << "The closest pair is [" << ar1[res_i] << ", "
         << ar2[res_j] << "] \n";
}

int main()
{
    int ar1[] = {1, 4, 5, 7};
    int ar2[] = {10, 20, 30, 40};
    int m = sizeof(ar1)/sizeof(ar1[0]);
    int n = sizeof(ar2)/sizeof(ar2[0]);
    int x = 39;
    printClosest(ar1, ar2, m, n, x);
    return 0;
}
