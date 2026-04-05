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

	int n;

	cin >> n;

	if ((n % 4 == 0) && (n % 100 != 0 || n % 400 == 0)) {
		cout << 1;
	}
	else {
		cout << 0;
	}

	return 0;
}