#include <iostream>
#include <stack>
using namespace std;

//float fuel[] = { 5,3,12,1,7 }; float dist[] = { 8,4,7,4,5 };
float fuel[] = { 3,4,6,3,7,11 }; float dist[] = { 3,10,2,4,6,9 };
int n = 6;
int FindMinimumPosition()
{
	float last = 0;
	int position = 0;
	float minimumFuel = 1;
	int minimumPosition = 0;

while (position < n) 
{ last += fuel[position];
last -= dist[position];
position++; // could be n which is past array bounds
if (last < minimumFuel)
{ minimumFuel = last; minimumPosition = position % n; //in case of last station
}
}
return minimumPosition ;
}
int main(){
	cout<< FindMinimumPosition();
}
