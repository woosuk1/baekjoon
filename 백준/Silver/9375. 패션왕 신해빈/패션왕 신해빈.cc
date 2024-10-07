#include<iostream>
#include <cstdio>
#include <algorithm> // for max
#include <vector>
#include <string>
#include <map>
#include <limits.h>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test_case, ans;

	cin >> test_case;

	int n;

	string a, b;

	while (test_case--) {
		map<string, int> mp;

		cin >> n;

		string input;

		for (int i = 0; i < n; i++) {
			cin >> a >> b;

			mp[b]++;
		}

		ans = 1;

		for (auto x : mp) {
			ans *= x.second + 1;
		}

		cout << ans - 1 << '\n';
	}


    return 0;
}
