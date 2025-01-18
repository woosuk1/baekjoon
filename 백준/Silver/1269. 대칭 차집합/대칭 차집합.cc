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
using namespace std;

using ll = long long;

int n, m;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	int temp;
	map<int, bool> mp;

	for (int i = 0; i < n + m; i++) {
		cin >> temp;
		
		if (mp[temp] == true)
			mp.erase(temp);
		else
			mp[temp] = true;
	}

	cout << mp.size();

	return 0;
}