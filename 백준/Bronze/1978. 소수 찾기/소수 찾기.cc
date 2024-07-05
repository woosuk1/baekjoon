#include <stdio.h>
#include <math.h>

int main() {
  int num, count =0, b;

  scanf("%d", &num);
  
  int a[num];
  
  for(int i=0; i<num; i++){
    scanf("%d", &a[i]);
  }
  
  for(int i=0; i<num; i++){
    b = sqrt(a[i]);  
    if(b == 1){
      if(a[i] != 1)
        count ++;
    }
    else{
      for(int j=2; j<=b; j++){
        //j가 b가 될 때까지 나누어 떨어지지 않으면 소수 
        if(a[i] % j == 0){ 
          break;
          }
        if(j == b)
          count ++;
      }
    }
    }
  printf("%d", count);
}
