import java.util.*;
import java.lang.*;
import java.io.*;
 
class Ideone {
 
    public static int getMaxRainwaterBetweenTowers(int[] arr) {
        int max_so_far = 0;
 
        int[] maxRight = new int[arr.length];
        int maxLeft = 0;
 
        int rainwater = 0;
 
        for (int i = arr.length - 1; i >= 0; i--) {
            if (arr[i] > max_so_far) {
                max_so_far = arr[i];
            } 
            maxRight[i] = max_so_far;
        }
 
        for (int i = 0; i < arr.length; i++) {
            rainwater = rainwater + Integer.max(Integer.min(maxLeft, maxRight[i]) - arr[i], 0);
            if (arr[i] > maxLeft) {
                maxLeft = arr[i];
            }
        }
 
        return rainwater;
    }
 
    public static void main(String[] args) {
        int[] towerHeight = { 1, 5, 2, 3, 1, 7, 2, 4 };
        //int[] towerHeight = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
        System.out.println(getMaxRainwaterBetweenTowers(towerHeight));
    }
}