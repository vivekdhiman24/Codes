# your code goes here
import sys

def printClosest(ar1, ar2, m, n, x):
	diff = sys.maxint
	res_l = 0 
	res_r = 0
	l = 0
	r = n-1
	while( l<m and r>=0 ):
		if (abs( (ar1[l] + ar2[r] - x ) < diff)):
			res_l=l
			res_r=r
			diff=abs(ar1[l] + ar2[r] - x)
		if(ar1[l] + ar2[r] > x):
			r=r-1
		else:
			l=l+1
	
	print "closest pair ",ar1[res_l],"-",ar2[res_r]," for X ",x
ar1 = [1, 4, 5, 7];
ar2 = [10, 20, 30, 40];
m=len(ar1)
n=len(ar2)
x = 48
printClosest(ar1, ar2, m, n, x);
x = 38
printClosest(ar1, ar2, m, n, x);
x = 10
printClosest(ar1, ar2, m, n, x);
