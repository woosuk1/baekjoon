#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <deque>
#include <climits>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
using namespace std;

using ll = long long;

void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}


int main() {

	init();

	int n, ans =0;

	cin >> n;

	int arr[6];

	for (int i = 0; i < 6; i++) {
		cin >> arr[i];
	}

	int t, p;

	cin >> t >> p;

	for (int i = 0; i < 6; i++) {
		if (arr[i] % t == 0)
			ans += arr[i] / t;
		else
			ans += (arr[i] / t + 1);
	}

	cout << ans << '\n' << n / p << ' ' << n % p;

	return 0;
}