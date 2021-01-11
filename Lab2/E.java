import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] arr = new int[1000000];
        for (int i=0;i<arr.length-1;i++){
             f(arr,i+1);
        }
        for(int i=0;i<n;i++){
            int x = in.nextInt();
            System.out.println(arr[x]);
        }
    }
    public static void f(int[] arr, int n){
        if(n <= 3){
            arr[n] = 1;
        }else{
            int x = Math.round(n/2);
            arr[n] = arr[x-1]+arr[x+1]+arr[x];
        }
    }
}