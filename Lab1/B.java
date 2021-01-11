import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int line = in.nextInt();
        for(int i=0;i<line;i++){
            int k = 1;
            int n = in.nextInt();
            for(int j=0;j<n;j++){
                k = (((k+k) % 1000000007)+k)%1000000007;
            }
            System.out.println(k-1);
        }
    }
}