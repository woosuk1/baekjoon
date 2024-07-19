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

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {

	init();

	int n;
	int temp1, temp2;

	cin >> n;

	vector<pair<int, int>> hsh;

	for (int i = 0; i < n; i++) {	
		cin >> temp1 >> temp2;

		hsh.push_back(make_pair(temp1, temp2));
	}

	sort(hsh.begin(), hsh.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << hsh[i].first << ' ' << hsh[i].second << '\n';
	}


	return 0;
}