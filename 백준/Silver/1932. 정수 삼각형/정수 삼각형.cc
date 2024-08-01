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

int save[501][501];
int dp[501][501];

int main() {
	
	int n, ans = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> save[i][j];
		}
	}

	dp[0][0] = save[0][0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][0] = dp[i - 1][0] + save[i][0];
			}
			else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + save[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j - 1] + save[i][j], dp[i - 1][j] + save[i][j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[n-1][i]);
	}

	cout << ans;

	return 0;
}