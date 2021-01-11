import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int line = in.nextInt();
        for(int i =0;i<line;i++) {
            int number = in.nextInt();
            int k = 0,count=0;
            int[] stone = new int[number];
            for(int j =0;j<number;j++){
                stone[j] = in.nextInt();
                if(j == 0){
                    k = stone[0];
                    continue;
                }
                k = k ^ stone[j];
            }
            if(k == 0){
                System.out.println(0);
            }else {
                for(int j=0;j<number;j++){
                    if((k ^ stone[j]) < stone[j]){
                        count++;
                    }
                }
                System.out.println(count);
            }
        }
    }
}