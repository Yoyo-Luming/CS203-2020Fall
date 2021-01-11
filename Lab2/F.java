import java.util.Scanner;

public class Main {
    private static int xr;
    private static int yr;
    private static int xc;
    private static int yc;
    private static int n;
    private static int x_move=0;
    private static int y_move=0;
    private static char[] a;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        xr = in.nextInt();
        yr = in.nextInt();
        xc = in.nextInt();
        yc = in.nextInt();
        n = in.nextInt();
        String s = in.next();
        a = s.toCharArray();
        for (int i = 0; i < n; i++) {
            switch (a[i]) {
                case 'U':
                    y_move++;
                    break;
                case 'D':
                    y_move--;
                    break;
                case 'L':
                    x_move--;
                    break;
                case 'R':
                    x_move++;
                    break;
            }
        }
        if(xr == xc && yr ==yc){
            System.out.println(0);
            System.exit(0);
        }
        int xjud = x_move,yjud =y_move;
        if(xr < xc){
            xjud = - x_move;
        }
        if(yr < yc){
            yjud = - y_move;
        }
        if((xjud + yjud) == n){
            System.out.println(-1);
            System.exit(0);
        }
        long left = 0;
        long right = Long.MAX_VALUE;
        long mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if(move(mid))
                left = mid + 1;
            else
                right = mid;
        }
        if(right != Long.MAX_VALUE)
            System.out.println(left);
        else
            System.out.println(-1);
    }

    private static boolean  move(long minutes){
        long ci = minutes / n;
        int mod = (int) (minutes % n);
        long curxr = xr + x_move * ci;
        long curyr = yr + y_move * ci;
        if(mod != 0){
            for(int i=0;i<mod;i++){
                switch (a[i]){
                    case 'U':
                        curyr++;
                        break;
                    case 'D':
                        curyr--;
                        break;
                    case 'L':
                        curxr--;
                        break;
                    case 'R':
                        curxr++;
                        break;
                }
            }
        }
        long ccMinutes = Math.abs(curxr - xc) + Math.abs(curyr - yc);
        return ccMinutes > minutes;
    }
}
