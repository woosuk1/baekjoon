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

	int a[10001] = { 0 };

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		a[temp]++;
	}

	for (int i = 0; i < 10001; i++) {
		while (a[i]--) {
			cout << i << '\n';
		}
	}

	return 0;
}