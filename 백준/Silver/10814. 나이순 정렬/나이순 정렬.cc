#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 구조체를 쓰는 방법도 있을 듯함
typedef struct {
  int age;
  char name[101];
}id;



/*
stable quick sort 써야하는데 진짜 맛없다
void stable_quick_sort(id *array, int left, int right);
*/

int compare(const void* arg1, const void* arg2){
  id *a = (id*)arg1;
  id *b = (id*)arg2;
  //오름차순 ㅅ정렬
  if(a->age > b ->age) return 1;
  else if(a->age < b->age) return -1;
  else return 0;
}

int main() {
  id *a;
  int N, i = 0;

  scanf("%d", &N);

  a = (id*)malloc(N * sizeof(id));
  
  if (N < 1 || N > 100000) {
    printf("error");
    return -1;
  }

  while (i < N) {
    scanf("%d%*c%s", &a[i].age, a[i].name);
    i++;
  }

  qsort(a, N, sizeof(id), compare);
  i= 0;
  while (i < N) {
    printf("%d %s\n", a[i].age, a[i].name);
    i++;
  }
  free(a);
  return 0;
}
