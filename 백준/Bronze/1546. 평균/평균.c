#include <stdio.h>
#define CRT_SECURE_NO_WARNINGS
int main() {
	int a, max =0;
	double sum = 0;
	scanf("%d", &a);
	int arr[1000] = {0};
	if (a <= 1000) {
		for (int i = 0; i < a; i++)
		{
			scanf("%d", &arr[i]);
			if (0 < arr[i] && arr[i] <= 100) {
				if (max < arr[i])
					max = arr[i];
			}
			
		}
		if (max == 0) {
			printf("입력오류");
			return;
		}
		for (int j = 0; j < a; j++) {
			sum += (double)arr[j] / max * 100;
		}
		printf("%.2lf", sum / a);
	}

	return 0;
}