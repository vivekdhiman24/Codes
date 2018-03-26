#include <stdio.h>
#define R 3
#define C 4

void printMatrix(int mat[R][C])
{
	int i, j;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}
void modifyMatrix(int mat[R][C])
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if ( mat[i][j]== 1 )
			{   
				for(int p=0;p<R;p++) {mat[p][j] = mat[p][j] == 1?1:2;}
				for(int q=0;q<C;q++) {mat[i][q] = mat[i][q] == 1?1:2;}
			}
		}
	}
	for(int i = 0;i < R; i++)
	{
	    for(int j = 0; j < C; j++){
	        if( mat[i][j] == 2){
	            mat[i][j] = 1;
	        }      
	    }
	}
}

int main()
{
	int mat[R][C] = { {1, 0, 0, 1},
		{0, 0, 1, 0},
		{0, 0, 0, 0},
	};

	printf("Input Matrix \n");
	printMatrix(mat);

	modifyMatrix(mat);

	printf("Matrix after modification \n");
	printMatrix(mat);

	return 0;
}
