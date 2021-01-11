import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int line = in.nextInt();
        for(int i=0;i<line;i++){
            int x = in.nextInt();
            int y = in.nextInt();
            if(x ==1 && y == 1){
                System.out.println("Bob");
            }else {
                System.out.println("Alice");
            }
        }

    }
}