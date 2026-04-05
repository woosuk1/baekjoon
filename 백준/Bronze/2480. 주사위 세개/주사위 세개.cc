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

	int a, b, c;

	cin >> a >> b >> c;

	if ((a == b) && (b == c)) {
		cout << 10000 + 1000 * b;
		return 0;
	}

	if ((a != b) && (b != c) && (c != a)) {
		cout << max(a, max(b, c)) * 100;
		return 0;
	}

	if (a == b) {
		cout << 1000 + a * 100;
	}
	else {
		cout << 1000 + c * 100;
	}

	return 0;
}