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

	queue<int> q;

	int n, k;

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	int count = 0;

	cout << '<';

	while (!q.empty()) {
		if (q.size() == 1) {
			cout << q.front() << '>';
			break;
		}

		if (count < k-1) {
			q.push(q.front());
			q.pop();
			count++;
		}
		else {
			count = 0;
			cout << q.front() << ", ";
			q.pop();
		}
	}
	
	return 0;
}