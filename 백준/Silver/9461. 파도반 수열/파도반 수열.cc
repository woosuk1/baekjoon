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
using namespace std;

using ll = long long;

int main() {
	
	ll dp[102];

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= 101; i++) {
		dp[i] = dp[i - 3] + dp[i - 2];
	}

	int t, input;

	cin >> t;

	while (t--) {
		cin >> input;

		cout << dp[input-1] << '\n';
	}

	return 0;
}