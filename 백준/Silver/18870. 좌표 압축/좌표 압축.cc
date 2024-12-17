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
#include <sstream>

using namespace std;

using ll = long long;

void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main() {

	init();

	int n, count = 0;

	map<int, int> mp;

	cin >> n;

	int save[1000001];

	for (int i = 0; i < n; i++) {
		cin >> save[i];
		mp[save[i]] = 1;
	}

	for (auto &a : mp) {
		a.second = count++;
	}

	for (int i = 0; i < n; i++) {
		cout << mp[save[i]] << ' ';
	}
	return 0;
}