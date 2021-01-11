import java.util.Scanner;
public class Main {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int line = in.nextInt();
        int r, l;
        for(int i=0;i<line;i++){
            int c = in.nextInt();
            int k = in.nextInt();
            int g = in.nextInt();
            l = 2*c+1+2*k;
            r = 2*g+1+2*k;
            String[][] box = new String[r][l];
            for(int j = 0;j < r;j++){
                for(int m=0; m<2*c;m= m+2){
                    if(j<2*k){
                        if(j%2 == 0) {
                            box[j][m + 2 * k - j] = "+";
                            box[j][m + 2 * k - j + 1] = "-";
                        }else {
                            box[j][m + 2 * k - j] = "/";
                            box[j][m + 2 * k - j + 1] = ".";
                        }
                    }else {
                        if(j%2 == 0) {
                            box[j][m] = "+";
                            box[j][m + 1] = "-";
                        }else {
                            box[j][m] = "|";
                            box[j][m+ 1] = ".";
                        }
                    }
                }
            }
            for (int j = 0;j<2*k;j++){
                for(int m = 2*k-1-j;m>=0;m--){
                    box[j][m] = ".";
                    box[r-1-j][l-1-m]=".";
                }
            }
            for(int j=0;j<2*k+1;j++) {
                for(int m =0;m<2*g;m=m+2){
                    if(j%2==0){
                        box[m+j][l-j-1]="+";
                        box[m+1+j][l-j-1]="|";
                    }else {
                        box[m+j][l-j-1]="/";
                        box[m+1+j][l-j-1]=".";
                    }
                }
                if(j%2==0){
                    box[2*g+j][l-j-1]="+";
                }else {
                    box[2*g+j][l-j-1]="/";
                }
            }
            print(box);
        }
    }
    public static void print(String[][] box){
        for (String[] row : box){
            for (String date : row){
                System.out.print(date);
            }
            System.out.println();
        }
    }
}
