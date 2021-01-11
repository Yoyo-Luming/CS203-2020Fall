import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int[] num = new int[n];
        int[] eng = new int[m];
        for (int i = 0; i < n; i++) {
            num[i] = in.nextInt();
        }
        for (int i = 0; i < m; i++) {
            eng[i] = in.nextInt();
        }
        for (int i = 0; i < m; i++) {
            String out = binarySearch(num, n - 1, eng[i]);
            System.out.println(out);
        }
    }

    public static String binarySearch(int[] arr, int r, int k) {
        int l = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == k){
                return "Accept";
            } else if( arr[mid] > k){
                if((mid - 1)<0){
                    return String.valueOf(arr[mid] - k);
                }else {
                    if (arr[mid - 1] < k) {
                        return String.valueOf(k - arr[mid - 1]);
                    }
                }
                r  = mid - 1;
            }else {
                if((mid + 1) > r){
                    return String.valueOf(k - arr[mid]);
                }else {
                    if (arr[mid + 1] > k) {
                        return String.valueOf(k - arr[mid]);
                    }
                }
                l = mid  + 1;
            }
        }
        return "";
    }
}
