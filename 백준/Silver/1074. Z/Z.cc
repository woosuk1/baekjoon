#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

using ll = long long;

int ans;

void maze(int n, int r, int c) {
	int temp = pow(n, 2) / 4;
	int y = n / 2;
	int x = n / 2;

	if (r + 1 <= y && c + 1 <= x) {
		ans += temp * 0;
		if (temp == 1) return;
		maze(n / 2, r, c);
	}
	if (r + 1 <= y && c + 1 > x) {
		ans += temp * 1;
		if (temp == 1) return;
		maze(n / 2, r, c-x);
	}

	if (r + 1 > y && c + 1 <= x) {
		ans += temp * 2;
		if (temp == 1) return;
		maze(n / 2, r-y, c);
	}
	if (r + 1 > y && c + 1 > x) {
		ans += temp * 3;
		if (temp == 1) return;
		maze(n / 2, r - y, c-x);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, r, c;

	cin >> n >> r >> c;

	int po = pow(2, n);

	maze(po,r,c);

	cout << ans;

	return 0;
}