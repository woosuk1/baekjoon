#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

  // 1번 숫자를 문자열로 바꿔서, 뒤에서 부터 0 판별
  // 2번 숫자를 일의 자릿수부터 나머지 판별
  // 2번이 메모리가 조금 더 낫겠지?
  // 재귀 방식으로 해야함? 반복 방식으로 안되네
  // 생각해보니 5*n의 수가 나오면 n의 개수만큼 0이 나와. 근데 5 * 5^n수면 두자리씩 올라.

int main() {
	int N;
	int mul5 = 0;	// 5의 배수
	int mul25 = 0;	// 25의 배수
	int mul125 = 0;	// 125의 배수

	scanf("%d", &N);

	mul5 = N / 5;
	mul25 = N / 25;
	mul125 = N / 125;

	printf("%d", mul5 + mul25 + mul125);

	return 0;
}

  