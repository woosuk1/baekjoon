#include<iostream>
#include <cstdio>
#include <algorithm> // for max
#include <vector>
#include <string>
#include <map>
#include <limits.h>

using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;

	cin >> t;

	int m, n, x, y;

	while (t--) {
		int answer = -1;

		cin >> m >> n >> x >> y;
		int Max = lcm(m, n);

		for (int i = x; i <= Max; i += m) {
			int check = i % n;
			if (check == 0)
				check = n;

			if (check == y) {
				answer = i;
				break;
			}
		}
		cout << answer << '\n';
	}
	return 0;
}
