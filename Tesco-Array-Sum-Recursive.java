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
		int[] arr = {2,3,5,6,8,10};
		HashMap<String,Integer> resultset=new HashMap<String,Integer>();
		findNumbers(arr,0,0,999,"",resultset);
		if (resultset.size()!=0)
			System.out.println(resultset.size());
		else
			System.out.println(999);
	}
	static void findNumbers(int list[], int index, int current, int goal, String result,HashMap<String,Integer> resultset)
			{

			  if (list.length < index || current>goal)
			          return;
			   for (int i = index; i < list.length; i++) {
			      if (current + list[i] == goal && list[i]!=goal)   {
			      	 result+=""+Integer.toString(list[i]);
			      	 resultset.put(result,1);
			         //System.out.println(result+"-"+current+"-"+list[i]);
			       }
			       else if (current + list[i] < goal) {
			           findNumbers(list, i + 1, current + list[i], goal, result + "" + Integer.toString(list[i]),resultset);
			        }
			  }
		}
}
