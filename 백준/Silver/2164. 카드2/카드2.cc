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

using namespace std;

using ll = long long;

int main() {

	queue<int> q;

	int n, ans;

	cin >> n;

	if (n == 1) {
		cout << 1;
		return 0;
	}

	for (int i = 1; i <=n; i++) {
		q.push(i);
	}

	while (!q.empty()) {
		q.pop();

		if (q.size() == 1) {
			ans = q.front();
			break;
		}

		q.push(q.front());
		q.pop();
	}

	cout << ans;

	return 0;
}