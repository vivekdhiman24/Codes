#include <stdio.h>
#include <stdbool.h>
int max(int a, int b){
    return (a > b)? a : b;
}

int lcs( char *X, char *Y, int m, int n ){
   if (m == 0 || n == 0)
     return 0;
   if (X[m-1] == Y[n-1])
     return 1 + lcs(X, Y, m-1, n-1);
   else
     return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}
int lcsDP( char *X, char *Y, int m, int n )
{
   int L[m+1][n+1];
   int i, j;

   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;

       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;

       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
   return L[m][n];
}
int lcsDPSpace(char *X, char *Y,int m,int n)
{

	int L[2][n+1];

	bool bi;
	for (int i=0; i<=m; i++)
	{
		bi = i&1;
        //printf("%d->%d\n",i,bi);
		for (int j=0; j<=n; j++)
		{
			if (i == 0 || j == 0)
				L[bi][j] = 0;
			else if (X[i] == Y[j-1])
				L[bi][j] = L[1-bi][j-1] + 1;
			else
				L[bi][j] = max(L[1-bi][j], L[bi][j-1]);
		}
	}
	return L[bi][n];
}

int main()
{
  char X[] = "AGGTAB";
  char Y[] = "GXTXAYB";
  int m = strlen(X);
  int n = strlen(Y);
  printf("Length of LCS is %d\n", lcs( X, Y, m, n ) );
  printf("Length of LCS is %d\n", lcsDP( X, Y, m, n ) );
  printf("Length of LCS is %d\n", lcsDPSpace( X, Y, m, n ) );
  return 0;
}
