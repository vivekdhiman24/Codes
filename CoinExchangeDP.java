/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

import java.util.ArrayList;
import java.util.List;
class Ideone {

    public int coinExchange(int total, int coins[]){
        int temp[][] = new int[coins.length+1][total+1];
        for(int i=0; i <= coins.length; i++){
            temp[i][0] = 1;
        }
        for(int i=1; i <= coins.length; i++){
            for(int j=1; j <= total ; j++){

                if(coins[i-1] > j){
                    temp[i][j] = temp[i-1][j];
                }
                else{
                    temp[i][j] = temp[i][j-coins[i-1]] + temp[i-1][j];
                }
                System.out.println(i+"-"+j+"-"+temp[i][j]);
            }
        }
        return temp[coins.length][total];
    }

    /*
     * Space efficient DP solution
     */
    public int coinExchangeSpace(int total, int arr[]){

        int temp[] = new int[total+1];

        temp[0] = 1;
        for(int i=0; i < arr.length; i++){
            for(int j=arr[i]; j <= total ; j++){

                    temp[j] += temp[j-arr[i]];

                System.out.println(i+"-"+j+"-"+temp[j]);
            }
        }
        return temp[total];
    }

    public static void main(String args[]){
        Ideone ce = new Ideone();
        int total = 5;
        int coins[] = {1,2,3};
        System.out.println(ce.coinExchange(total, coins));
        //System.out.println(ce.coinExchangeSpace(total, coins));
    }
}
