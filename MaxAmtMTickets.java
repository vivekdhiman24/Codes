/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		sc.nextLine();
		List<Integer> a = new ArrayList<Integer>();
		for(int i=0;i<n;i++)
		{
			int x = sc.nextInt();
			a.add(x);
		}
		System.out.println("N="+n);
		System.out.println("M="+m);
		System.out.println("Arry="+a);
		//Sort the array..
		Collections.sort(a,Collections.reverseOrder());
		//System.out.println(a);
		//System.out.println(m);

		int sum = 0;
		int i = 0;
		int j = 0;
		while(j<m) {
			int x = a.get(i);
			sum += x;
			j++;
			a.set(i,a.get(i)-1);
			Collections.sort(a,Collections.reverseOrder());
			//if(a.get(i+1) > a.get(i) ) {
			//	i++;
			//}
		}
			System.out.println(sum);
	}
}
