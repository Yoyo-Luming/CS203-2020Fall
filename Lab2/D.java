import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int len = in.nextInt();
        int[] tree = new int[n];
        int[] distance = new int[n];
        tree[0] = in.nextInt();
        for(int i=1;i<n;i++){
            tree[i] = in.nextInt();
            int i1 = tree[i] - tree[i - 1];
            distance[i-1] = i1;
            if(i == n-1){
                distance[i] = len - tree[i];
            }
        }
        int runDistance = splitArray(distance, m);
        System.out.println(runDistance);
    }

    private static int splitArray(int[] a, int m) {
        int max = 0;
        int sum = 0;
        for (int num : a) {
            max = Math.max(max, num);
            sum += num;
        }
        int l = max;
        int r = sum;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int s = split(a, mid);
            if (s > m) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }

    private static int split(int[] a, int maxSum) {
        int s = 1;
        int curSum = 0;
        for (int num : a) {
            if (curSum + num > maxSum) {
                curSum = 0;
                s++;
            }
            curSum += num;
        }
        return s;
    }
}