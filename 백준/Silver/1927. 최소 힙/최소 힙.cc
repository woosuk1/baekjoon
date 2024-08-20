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

void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main() {

	init();
	
	int t;

	cin >> t;

	priority_queue<int> pq;

	int temp;

	for (int i = 0; i < t; i++) {
		cin >> temp;
		//음수로 나타내기
		temp = -temp;

		if (temp < 0) {
			pq.push(temp);
		}
		else {
			if (pq.empty()) {
				cout << 0 << '\n';
				continue;
			}
			else {
				cout << -pq.top() << '\n';
				pq.pop();
			}
		}
	}

	return 0;
}