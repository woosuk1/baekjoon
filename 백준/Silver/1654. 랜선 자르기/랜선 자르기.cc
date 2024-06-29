#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long k, n, cnt = 0, lines, mid =0;

	long long arr[10001];

	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		if (cnt < arr[i]) cnt = arr[i];
	}

	long long start = 1, end = cnt, res = 0;

	while (start <= end) {

		mid = (start + end) / 2;

		lines = 0;

		for (int i = 0; i < k; i++) {
			lines += arr[i] / mid;
		}

		if (lines >= n) {
			start = mid + 1;
			if (res < mid) res = mid;
		}
		else
			end = mid - 1;

	}

	cout << res << endl;
}
