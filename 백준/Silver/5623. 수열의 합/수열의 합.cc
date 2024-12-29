#include<iostream>
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

	int arr[1001][1001] = { 0 };

	int ans[1001] = { 0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	if (n != 2) {
		int zero = (arr[0][1] + arr[0][2] - arr[1][2]) / 2;
		for (int i = 0; i < n; i++) {
			if (i == 0)
				ans[i] = zero;
			else
				ans[i] = arr[0][i] - zero;

			cout << ans[i] << ' ';
		}
	}
	else {
		cout << "1 1" << '\n';
	}

	return 0;
}