import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;

public class Main {
    private static int n,k;
    private static long m;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int caseNum = in.nextInt();
        for (int i = 0; i < caseNum; i++) {
            n = in.nextInt();
            k = in.nextInt();
            m = in.nextLong();
            Integer[] a = new Integer[n];
            for (int j = 0; j < n; j++) {
                a[j] = in.nextInt();
            }
            int left = Collections.min(Arrays.asList(a));
            int right = Collections.max(Arrays.asList(a));
            int mid;
            while (left < right){
                mid = right - (right - left) / 2;
                if(find(a,mid))
                    left = mid;
                else
                    right = mid-1;
            }
            System.out.println(left);
        }
    }
    private static boolean find(Integer[] a, int mid){
        long qujian = 0;
        int num = 0;
        int j = 1;
        for(int i=1; i< n;i++){
            if(a[i] >= mid){
                num++;
            }
            if(num == k){
                qujian = qujian + n - i + 1;
                while (a[j]<mid){
                    qujian = qujian + n - i + 1;
                    j++;
                }
                num--;
                j++;
            }
        }
        return qujian >= m;
    }
}
