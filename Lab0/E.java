import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int line = in.nextInt();
        for (int i=0;i<line;i++) {
            int temp =0;
            int number = in.nextInt();
            int[] list = new int[number];
            for (int j = 0; j < number; j++) {
                list[j] = in.nextInt();
            }
            int dif = list[0] - list[1];
            for (int m = 0; m < number - 1; m++) {
                if (m > 1) {
                    if (list[m] > list[temp]) {
                        for (int n = m + 1; n < number; n++) {
                            if (dif < (list[m] - list[n])) {
                                dif = list[m] - list[n];
                            }
                        }
                        temp = m;
                    }
                } else {
                    for (int n = m + 1; n < number; n++) {
                        if (dif < (list[m] - list[n])) {
                            dif = list[m] - list[n];
                        }
                    }
                }
            }
            System.out.println(dif);
        }
    }
}