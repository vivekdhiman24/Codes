/* Rat in Maze Backtracking */
#include<stdio.h>
#define N 5


void printSolution(int path[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        printf(" %d ", path[i][j]);
        printf("\n");
    }
}

bool isSafe(int maze[N][N], int x, int y)
{
    if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
    return true;
    return false;
}


bool solveMazeUtil(int maze[N][N], int i, int j, int path[N][N])
{
    if(i == N-1 && j == N-1)
    {
        path[i][j] = 1;
        return true;
    }

    if(isSafe(maze, i, j) == true)
    {
        path[i][j] = 1;

        if (solveMazeUtil(maze, i+1, j, path) == true)
        return true;

        if (solveMazeUtil(maze, i, j+1, path) == true)
        return true;
        if (solveMazeUtil(maze, i-1, j, path) == true)
        return true;

        if (solveMazeUtil(maze, i, j-1, path) == true)
        return true;

        path[i][j] = 0;
        return false;
    }

    return false;
}

int main()
    {
        int maze[N][N] = {
        	{1, 1, 0, 0, 0},
            {0, 1, 0, 0, 1},
            {1, 1, 1, 0, 0},
            {1, 0, 0, 0, 0},
            {1, 1, 1, 1, 1}
        };
        int path[N][N] = {
        	{0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}
        };


        if(solveMazeUtil(maze, 0, 0, path) == false)
        printf("Solution doesn't exist");

        else
        printSolution(path);

        return 0;
}
