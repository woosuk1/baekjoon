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
	
	int n, m;

	cin >> n >> m;

	vector<string> vec(n+1);
	map<string, int> mp;
	
	for (int i = 1; i <= n; i++) {
		cin >> vec[i];
		mp.insert({ vec[i], i });
	}

	string temp;

	for (int i = 0; i < m; i++) {
		cin >> temp;
		if (temp[0] >= '0' && temp[0] <= '9') {
			cout << vec[stoi(temp)] << '\n';
		}
		else
			cout << mp[temp] << '\n';
	}

	return 0;
}