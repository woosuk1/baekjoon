#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <queue>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a[7];
	int sum = 0;
	int min_x = 101;

	for (int i = 0; i < 7; i++) {
		cin >> a[i];
		if (a[i] % 2 != 0) {
			sum += a[i];
			min_x = min(a[i], min_x);
		}
	}

	if (sum == 0)
		cout << -1;
	else
		cout << sum << '\n' << min_x;

	return 0;
}