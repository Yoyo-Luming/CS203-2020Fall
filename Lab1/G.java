import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int line = in.nextInt();
        for(int i=0;i<line;i++){
            long n = in.nextLong();
            int s = in.nextInt();
            int wei,temp = 0;
            long m, x=0;
            String ss = String.valueOf(n);
            wei = ss.length();
            long[] num = new long[wei+1];
            num[0] = 0;
            for(int j=1;j<wei+1;j++) {
                num[j] = Long.parseLong(String.valueOf(ss.charAt(j-1)));
            }
            m = 0;
            for(int j=1;j<num.length;j++){
                x = x + num[j];
                if(x > s){
                    if(temp != 0){
                        num[temp-1]++;
                        for(int k=0;k<temp;k++){
                            long y = 1;
                            for(int gan=0;gan<wei-k;gan++){
                                y=y*10;
                            }
                            m = m +  (num[k] * y);
                        }
                        System.out.println(m-n);
                        break;
                    }else {
                        num[j-1]++;
                        for(int k=0;k<j;k++){
                            long y = 1;
                            for(int gan=0;gan<wei-k;gan++){
                                y=y*10;
                            }
                            m = m +  (num[k] * y);
                        }
                        System.out.println(m-n);
                        break;
                    }

                }
                if(x == s){
                    if(temp == 0){
                        temp = j;
                    }
                    if(wei == 1){
                        m = n;
                        System.out.println(m-n);
                        break;
                    }
                }
            }
            if(m ==0){
                System.out.println(0);
            }
        }
    }
}