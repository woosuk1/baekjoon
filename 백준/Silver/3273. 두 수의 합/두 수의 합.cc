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

	int n, x;

	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cin >> x;

	sort(arr.begin(), arr.end());

	// 투 포인터 돌릴 것들
	int start = 0, end = n- 1;

	int ans = 0;

	while (start < end) {
		if (arr[start] + arr[end] < x) {
			start++;
		}
		else if (arr[start] + arr[end] > x) {
			end--;
		}
		else if (arr[start] + arr[end] == x) {
			start++;
			end--;
			ans++;
		}

		if (start == end)
			break;
	}

	cout << ans;

	return 0;
}
