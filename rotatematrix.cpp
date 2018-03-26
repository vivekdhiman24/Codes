// Rotate matrix With transpose and Reverse Method
#include<bits/stdc++.h>
using namespace std;
#define R 4
#define C 4
void printMatrix(int arr[R][C]){
	for (int i=0; i<R; i++)
	{
		for (int j=0; j<C; j++)
			cout << arr[i][j] << " ";
		cout<<'\n';
	}
}
void reverseColumns(int arr[R][C]){
	for (int i=0; i<C; i++)
		for (int j=0, k=C-1; j<k; j++,k--)
			swap(arr[j][i], arr[k][i]);
}
void reverseRows(int arr[R][C]){
    for(int i=0;i<R;i++)
        for(int j=0,k=R-1;j<k;j++,k--)
            swap(arr[i][j],arr[i][k]);
}
void transpose(int arr[R][C]){
	for (int i=0; i<R; i++)
		for (int j=i; j<C; j++)
			swap(arr[i][j], arr[j][i]);
}
void rotate90AntiClock(int arr[R][C]){
	transpose(arr);
	reverseColumns(arr);
}
void rotate90Clock(int arr[R][C]){
	transpose(arr);
	reverseRows(arr);
}

int main()
{
	int arr[R][C]= { {1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};
	rotate90AntiClock(arr);
	cout<<'\n';
	printMatrix(arr);
	cout<<'\n';
	int arr2[R][C]= { {1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};
	rotate90Clock(arr2);
	printMatrix(arr2);
	return 0;
}
