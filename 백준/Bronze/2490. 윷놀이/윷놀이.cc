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

	int a[4];
	int count;

	for (int i = 0; i < 3; i++) {
		count = 0;
		for (int j = 0; j < 4; j++) {
			cin >> a[j];
			if (a[j] == 0)
				count++;
		}

		if (count == 0) {
			cout << 'E';
		}
		else if (count == 1) {
			cout << 'A';
		}
		else if (count == 2) {
			cout << 'B';
		}
		else if (count == 3) {
			cout << 'C';
		}
		else if (count == 4) {
			cout << 'D';
		}

		cout << '\n';
	}

	return 0;
}