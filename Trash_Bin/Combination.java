package Trash_Bin;

import java.io.*;
import java.util.*;

public class Combination {

    static boolean[] chk;
    static int[] arr = { 1, 2, 3, 4 };

    static void recur(int n) {
        if (n == chk.length) {
            System.out.print("{");
            for (int i = 0; i < chk.length; i++) {
                if (chk[i])
                    System.out.print(arr[i] + ", ");
            }
            System.out.println("}");
            return;
        }
        recur(n + 1);
        chk[n] = true;
        recur(n + 1);
        chk[n] = false;
    }

    static void bit_masking() {
        for(int i = 0;i<(1<<arr.length);i++){
            System.out.print("{");
            for(int j = 0;j<arr.length;j++){
                if((i&(1<<j))!=0)
                    System.out.print(arr[j]+", ");
            }
            System.out.print("}\n");
        }
    }

    public static void main(String[] args) {
        chk = new boolean[arr.length];
        // recur(0);
        bit_masking();
    }
}
