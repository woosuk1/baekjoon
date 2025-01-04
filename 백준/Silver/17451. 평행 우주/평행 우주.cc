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

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	long long init_value = arr[n-1];

	for (int i = n-2; i >= 0; i--) {
		if (arr[i] > init_value) { // 오름차순
			init_value = arr[i];
		}
		else {
			if (init_value % arr[i]) { // 내림차순
				init_value = (init_value / arr[i] + 1) * arr[i];
			}
		}
	}

	cout << init_value;

	return 0;
}