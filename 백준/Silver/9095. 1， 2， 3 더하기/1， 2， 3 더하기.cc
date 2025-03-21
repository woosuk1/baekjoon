#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int dp[1001] = {0,};

int cal(int num);

int main() {

  int N, i = 0;

  scanf("%d", &N);

  while(i<N){
    int d;
    scanf("%d", &d);
    
    printf("%d\n", cal(d));
    i++;
  }
  
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
  dp[3] = 4;
  
  for(int i =4; i<num+1; i++){
    dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]);
  }
  return dp[num];
}
