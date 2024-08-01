#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int dp[1001] = {0,};

int cal(int num);

int main() {

  int N;

  scanf("%d", &N);

  printf("%d", cal(N));
  
  return 0;
}

/*
bottom up
n=1 , n
n=2 , n
n=3 , n
n=4 , n+ 2c2
n=5, 

*/


//bottom up
int cal(int num){

  dp[1] = 1;
  dp[2] = 2;
  
  for(int i =3; i<num+1; i++){
    dp[i] = (dp[i-1] + dp[i-2]) % 10007;
  }
  return dp[num];
}
