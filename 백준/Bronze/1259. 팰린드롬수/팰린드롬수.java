import java.util.Objects;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        //자바 입력 클래스 scanner
        Scanner sc = new Scanner(System.in);

        String temp;

        while(true){
            //'\n'을 읽지 않는 입력
            temp = sc.nextLine();

            //문자열 비교 api
            if(Objects.equals(temp, "0")){
                break;
            }

            int a = temp.length();

            if(a % 2 == 0){
                //c++ substr처럼 인자가 2개 일 때 [first, end) 범위
                String temp1 = temp.substring(0, a/2);
                //reverse를 하기 위해,,,, StringBuilder 클래스 호출
                StringBuilder sb = new StringBuilder(temp.substring(a/2));
                String temp2 = sb.reverse().toString();

                //문자열 비교
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