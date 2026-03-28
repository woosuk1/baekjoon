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

	int n, x, temp;

	cin >> n >> x;

	for (int i = 0; i < n; i++) {
		cin >> temp;

		if (temp < x) cout << temp << " ";
		else continue;
	}

	return 0;
}