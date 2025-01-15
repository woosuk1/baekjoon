#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <vector>
#include <string>
#include <map>
#include <limits.h>
#include <queue>
#include <set>
#include <math.h>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;

	cin >> n;
	
	int arr[10] = { 0 };

	int ans = 0;

	while (n > 0) {
		if (n % 10 == 6 || n % 10 == 9) {
			arr[6]++;
		}
		else {
			arr[n % 10]++;
		}

		n /= 10;
	}

	for (int i = 0; i < 9; i++) {
		if (i == 6) {
			if (arr[6] % 2 == 0)
				ans = max(ans, arr[6] / 2);
			else
				ans = max(ans, arr[6] / 2 + 1);
		}
		else {
			ans = max(ans, arr[i]);
		}
	}

	cout << ans;

	return 0;
}
