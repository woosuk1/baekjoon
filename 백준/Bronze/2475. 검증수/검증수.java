import java.util.*;

public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        
        int input, sum = 0;
        
        for(int i=0; i<5; i++){
            input = sc.nextInt();
            
            sum += input * input;
        }
        
        System.out.println(sum % 10);
    }
}