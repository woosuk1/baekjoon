#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int STACK[10001];
int top = -1;

void push(int num);
int pop(void);


int main() {

  int N ,num, i = 0;
  char a[6]; //strtok 후 저장
  //명령의 개수
  scanf("%d", &N); 

  while(i < N){
    //명령어 입력
    scanf("%s", a);
    //버퍼 비우기
    fgetc(stdin);
    
    if(strcmp(a, "pop") == 0){
      pop();
      // printf("%d\n", STACK[top]);
    }
    else if(strcmp(a, "size") == 0){
      if(top == -1)
        printf("0\n");
      else
        printf("%d\n", top+1);
    }
    else if(strcmp(a, "empty") == 0){
      if(top == -1)
        printf("1\n");
      else
        printf("0\n");
    }
    else if(strcmp(a, "top") == 0){
      if(top == -1){
        printf("-1\n");
      }
      else
        printf("%d\n", STACK[top]);
    }
    else{
      scanf("%d", &num);
      fgetc(stdin);
      push(num);
    }
    i++;
  }
  
  return 0;
}

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
