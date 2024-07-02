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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	map<int, int> mp;


	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;

		mp.insert({ temp,1 });
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		int temp2;
		cin >> temp2;

		if (mp[temp2] == 1)
			cout << "1\n";
		else
			cout << "0\n";
	}
	return 0;
}