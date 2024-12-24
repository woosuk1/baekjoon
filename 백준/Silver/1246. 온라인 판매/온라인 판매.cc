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

	int n, m;

	cin >> n >> m;
	
	vector<int> arr;

	int temp, ans = 0, ans_value = 0;

	for (int i = 0; i < m; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	// 내림차 순
	sort(arr.rbegin(), arr.rend());

	for (int i = 0; i < m; i++) {
		if (i >= n)
			break;

		if (ans < arr[i] * (i + 1)) {
			ans = arr[i] * (i + 1);
			ans_value = arr[i];
		}
	}

	cout << ans_value << ' ' << ans;

    return 0;
}
