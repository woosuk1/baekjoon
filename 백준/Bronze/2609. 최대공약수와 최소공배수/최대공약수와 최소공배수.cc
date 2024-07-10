#include <stdio.h>

int main() {
  int a,b,mul,r;

  scanf("%d %d", &a, &b);
  mul = a * b; //최소공배수는 두수곱 /최대공약수 
  //유클리드 호제법
  while(b != 0){
    r = a % b;
    a = b;
    b = r;
  }
  printf("%d\n%d", a, mul/a);
}
  