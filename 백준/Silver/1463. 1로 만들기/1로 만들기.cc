#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int dp[1000001] = {0,};

int cal(int num);
int min(int a, int b);

int main() {

  int N;

  scanf("%d", &N);

  printf("%d", cal(N));
  
  return 0;
}

int min(int a, int b){
  if(a<b)
    return a;
  else
    return b;
}

//bottom up
int cal(int num){
  for(int i =2; i<num+1; i++){
    dp[i] = dp[i-1] +1;
    if(i%2 == 0){
      dp[i] = min(dp[i], dp[i/2]+1); 
    }
    if(i%3 == 0){
      dp[i] = min(dp[i], dp[i/3] + 1);
    }
  }
  return dp[num];
}
