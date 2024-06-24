import java.util.Scanner;
import java.io.*;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
//        Scanner sc = new Scanner(System.in);
        int a;
        int save = 666;
        String temp;

        a = sc.nextInt();

        int count = 0, flag = 0;

        while(flag == 0){
            temp = Integer.toString(save);
            for(int i=0; i<temp.length()-2; i++){
                if(temp.charAt(i) == '6' && temp.charAt(i+1) == '6' && temp.charAt(i+2) == '6'){
                    count++;
                    if(count == a){
                        flag = 1;
                        save--;
                    }
                    break;
                }
            }
            save++;
        }

        System.out.println(save);
    }
}