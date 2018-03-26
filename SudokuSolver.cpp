#include <stdio.h>
#define UNASSIGNED 0
#define N 9

bool FindUnassignedLocation(int arr[N][N], int &row, int &col)
{
    for (row = 0; row < N; row++)
    for (col = 0; col < N; col++)
    if (arr[row][col] == UNASSIGNED)
				return true;
    return false;
}

bool UsedInRow(int arr[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
    if (arr[row][col] == num) return true;
    return false;
}
bool UsedInCol(int arr[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
    if (arr[row][col] == num) return true;
    return false;
}
bool UsedInBox(int arr[N][N], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
    for (int col = 0; col < 3; col++)
    if (arr[row+boxStartRow][col+boxStartCol] == num) return true;
    return false;
}

bool isSafe(int arr[N][N], int row, int col, int num)
{
    return !UsedInRow(arr, row, num) &&
        !UsedInCol(arr, col, num) &&
        !UsedInBox(arr, row - row%3 , col - col%3, num);
}
void printarr(int arr[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        printf("%2d", arr[row][col]);
        printf("\n");
    }
}

bool SolveSudoku(int arr[N][N])
{
    int row, col;

    if (!FindUnassignedLocation(arr, row, col))
    return true;
    
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(arr, row, col, num))
        {
            arr[row][col] = num;
            if (SolveSudoku(arr))
            return true;
            arr[row][col] = UNASSIGNED;
        }
    }
    return false;
}



int main()
    {
        int arr[N][N] = {
        	{3, 0, 6, 5, 0, 8, 4, 0, 0},
            {5, 2, 0, 0, 0, 0, 0, 0, 0},
            {0, 8, 7, 0, 0, 0, 0, 3, 1},
            {0, 0, 3, 0, 1, 0, 0, 8, 0},
            {9, 0, 0, 8, 6, 3, 0, 0, 5},
            {0, 5, 0, 0, 9, 0, 6, 0, 0},
            {1, 3, 0, 0, 0, 0, 2, 5, 0},
            {0, 0, 0, 0, 0, 0, 6, 7, 4},
            {0, 0, 5, 2, 0, 6, 3, 0, 0}};
        if (SolveSudoku(arr) == true)
        printarr(arr);
        else
        printf("No solution exists");
        
        return 0;
}
