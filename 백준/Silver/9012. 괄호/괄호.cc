#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
int STACK[10001];
int top = -1;

void push(int num);
int pop(void);
*/

int main() {

  int N, i=0;
  char vps[50];

  scanf("%d", &N);

  while(i<N){

    int cnt = 0, cnt2 = 0;
    scanf("%s", vps);

    fgetc(stdin); //입력 버퍼 비우기

    if(vps[0] == '(' && vps[strlen(vps) -1] == ')'){
      for(int j =0; j< strlen(vps); j++){
        if(cnt >= cnt2){ // )가 더 많을 때
          if(vps[j] == '(')
            cnt++;
          else
            cnt2++;
        }
        else
          break;
      }
      if(cnt == cnt2)
        printf("YES\n");
      else
        printf("NO\n");
    }
    else
      printf("NO\n");
    i++;    
  }

  // int N ,num, i = 0;
  // char a[6]; //strtok 후 저장
  // //명령의 개수
  // scanf("%d", &N); 

  // while(i < N){
  //   //명령어 입력
  //   scanf("%s", a);
  //   //버퍼 비우기
  //   fgetc(stdin);
    
  //   if(strcmp(a, "pop") == 0){
  //     pop();
  //     // printf("%d\n", STACK[top]);
  //   }
  //   else if(strcmp(a, "size") == 0){
  //     if(top == -1)
  //       printf("0\n");
  //     else
  //       printf("%d\n", top+1);
  //   }
  //   else if(strcmp(a, "empty") == 0){
  //     if(top == -1)
  //       printf("1\n");
  //     else
  //       printf("0\n");
  //   }
  //   else if(strcmp(a, "top") == 0){
  //     if(top == -1){
  //       printf("-1\n");
  //     }
  //     else
  //       printf("%d\n", STACK[top]);
  //   }
  //   else{
  //     scanf("%d", &num);
  //     fgetc(stdin);
  //     push(num);
  //   }
  //   i++;
  // }
  
  return 0;
}
/*
void push(int num){
  if(top >= 10000){
    printf("stack overflow\n");
    return;
  }
  STACK[++top] = num;
}

int pop(){
  if(top == -1){
    printf("-1\n");
    return -1;
  }
  printf("%d\n", STACK[top]);
  return STACK[top--];
}
*/