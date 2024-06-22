import java.util.Objects;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        //자바 입력 클래스 scanner
        Scanner sc = new Scanner(System.in);

        String temp;

        while(true){
            temp = sc.nextLine();

            if(Objects.equals(temp, "0")){
                break;
            }

            int a = temp.length();

            if(a % 2 == 0){
                String temp1 = temp.substring(0, a/2);
                StringBuilder sb = new StringBuilder(temp.substring(a/2));
                String temp2 = sb.reverse().toString();

                if(temp1.equals(temp2)){
                    System.out.println("yes");
                }
                else{
                    System.out.println("no");
                }
            }
            else{
                String temp1 = temp.substring(0, a / 2);
                StringBuilder sb = new StringBuilder(temp.substring(a/2 + 1));
                String temp2 = sb.reverse().toString();

                if(temp1.equals(temp2)){
                    System.out.println("yes");
                }
                else{
                    System.out.println("no");
                }

            }
        }
    }
}