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

	int n, m;
	int left, right;
	int ans = 0;
	cin >> n >> m;

	deque<int> dq;

	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}	

	for (int i = 0; i < m; i++) {	
		int num;
		cin >> num;

		for (int i = 0; i < dq.size(); i++) {
			if (dq[i] == num) {
				left = i;
				right = dq.size() - i;
				break;
			}
		}

		if (left <= right) {
			while (1) {
				if (dq.front() == num)
					break;

				dq.push_back(dq.front());
				dq.pop_front();
				ans++;
			}
			dq.pop_front();
		}
		else {
			ans++; //앞으로 와야지 되니까 +1
			while (1) {
				if (dq.back() == num)
					break;

				dq.push_front(dq.back());
				dq.pop_back();
				ans++;
			}
			dq.pop_back();
		}
	}

	cout << ans;

	return 0;
}