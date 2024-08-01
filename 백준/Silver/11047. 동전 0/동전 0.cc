#include<iostream>
#include <cstdio>
#include <algorithm> // for max
#include <vector>
#include <string>
using namespace std;

int main() {

	int n, m ,k = 0; // n개의 단위, m은 거스름돈
	int arr[11];

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (int i = n; i > 0; i--) {
		k += m / arr[i];
		m %= arr[i];
	}

	printf("%d", k);

	return 0;
}
