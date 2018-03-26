#include <limits.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int min(int a, int b){  return a < b ? a : b; }

int findMinInsertionsRec(char str[], int l, int h)
{
    if (l > h) return INT_MAX;
    if (l == h) return 0;
    if (l == h - 1) return (str[l] == str[h])? 0 : 1;

    return (str[l] == str[h])? findMinInsertionsRec(str, l + 1, h - 1):
                               (min(findMinInsertionsRec(str, l, h - 1),
                                   findMinInsertionsRec(str, l + 1, h)) + 1);
}
int findMinInsertionsDP(char str[], int n)
{
    int table[n][n], l, h, gap;
    memset(table, 0, sizeof(table));

    for (gap = 1; gap < n; ++gap){
        for (l = 0, h = gap; h < n; ++l, ++h){



            table[l][h] = (str[l] == str[h])? table[l+1][h-1] :
                          (min(table[l][h-1], table[l+1][h]) + 1);

            printf("%c,%c->%d \n",str[l],str[h],table[l][h]);
        }

    }
    return table[0][n-1];
}
int findMinInsertionsDP2(string& str)
{
	int n = str.size();
	if( n == 0 )
		return 0;
	int table[n][n];
	int i,j;
	for( i = n-1; i >= 0; i-- )
	{
		for( j = i+1; j < n; j++ )
		{
			if( str[i] == str[j] )
			{
				if( j-i > 1 )
					table[i][j] = table[i+1][j-1];
			}
			else
			{
				table[i][j] = 1;
				if( j-i > 1 )
					table[i][j] = min(table[i][j-1], table[i+1][j])+1;
			}
		}
	}
	return table[0][n-1];
}

int main()
{
    char str[] = "abcad";
    string str1="abad";
    //printf("%d\n", findMinInsertionsRec(str, 0, strlen(str)-1));
    cout << findMinInsertionsDP(str,strlen(str))<<endl;
    //cout << findMinInsertionsDP2(str1)<<endl;

    return 0;
}
