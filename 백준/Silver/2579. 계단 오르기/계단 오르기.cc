#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <deque>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	vector<int> arr(n+1);
	vector<int> d(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	//arr[2], arr[1] 둘다 고르면 count = 2 arr[2]만 고르면 count = 1
	
	d[1] = arr[1];
	d[2] = arr[1] + arr[2];
	d[3] = max(arr[1] + arr[3], arr[2] + arr[3]);

	for (int i = 4; i <= n; i++) {
			d[i] = max(d[i-3] + arr[i - 1] + arr[i],d[i - 2] + arr[i]);
	}

	cout << d[n];

	return 0;
}