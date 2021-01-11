import  java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int line = in.nextInt();
        int[][]  content = new int[line][3];
        for(int i=0;i<line;i++){
            content[i][0] = in.nextInt();
            content[i][1] = in.nextInt();
            content[i][2] = in.nextInt();
        }
        for(int i=0;i<line;i++){
            System.out.println(function(content[i][0],content[i][1],content[i][2]));
        }
        //return 0;
    }

    public static int function(int a, int b, int n){
        if(n % 3 == 0){
                return a;
            }else if(n % 3 == 1) {
                return b;
            }else {
                return a ^ b;
            }
    }
}