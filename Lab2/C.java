import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int s = in.nextInt();
        int[] a = new int[n];
        long[][] difnum= new long[n][2];
        int point = 0;
        long count = 0;
        a[0] = in.nextInt();
        difnum[0][0] = a[0];
        difnum[0][1] = 1;
        for (int i = 1; i < n; i++) {
            a[i] = in.nextInt();
            if(a[i] != a[i-1]){
                point++;
                difnum[point][0] = a[i];
                difnum[point][1] = 1;
            }else {
                difnum[point][1]++;
            }
        }
        for(int i=0;i<=point;i++){
            if(3*difnum[i][0] > s)
                break;
            for(int j=i;j<=point;j++){
                if((difnum[i][0] +2*difnum[j][0]) > s)
                    break;
                int k = binarySearch(difnum,i,j,s,point);
                if(k != -1) {
                    count = count + count(difnum, i, j, k);
                }
            }
        }
        System.out.println(count);
    }

    public static int binarySearch(long[][] difnum, int i, int j, int s, int point){
        int l = j, r = point;
        while (l <= r){
            int mid = l + (r - l) / 2;
            if ((difnum[i][0]+difnum[j][0]+difnum[mid][0]) == s){
                return mid;
            } else if( (difnum[i][0]+difnum[j][0]+difnum[mid][0]) > s){
                r  = mid - 1;
            }else {
                l = mid  + 1;
            }
        }
        return -1;
    }

    public static long count(long[][] difnum,int i,int j,int k){
        long count = 0;
        if( i != j && j !=k){
            count =  difnum[i][1]*difnum[j][1]*difnum[k][1];
        } else if(i != j){
            if(difnum[j][1]>1){
                count =  difnum[i][1] * (difnum[j][1]*(difnum[j][1]-1))/2;
            }
        } else if(j != k){
            if(difnum[j][1]>1){
                count =  difnum[k][1] * (difnum[j][1]*(difnum[j][1]-1))/2;
            }
        } else {
            if(difnum[i][1]>2){
                count = (difnum[i][1] *(difnum[i][1]-2)*(difnum[i][1]-1))/6;
            }
        }
        return count;
    }
}
