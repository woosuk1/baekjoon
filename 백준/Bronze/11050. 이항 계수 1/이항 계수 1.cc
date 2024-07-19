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
	
	int n, k;
	
	cin >> n >> k;

	int ans = 1;

	for (int i = 2; i <= n; i++) {
		ans *= i;
	}

	for (int i = 1; i <= k; i++) {
		ans /= i;
	}
	
	for (int i = 1; i <= n-k; i++) {
		ans /= i;
	}

	cout << ans;
	
	return 0;
}