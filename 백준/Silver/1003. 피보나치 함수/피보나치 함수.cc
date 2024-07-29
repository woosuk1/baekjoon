#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;


int main() {

	int n;

	cin >> n;

	int d[41] = { 0,1,1 };

	for (int i = 3; i < 41; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 0)
			cout << 1 << ' ' << 0 << '\n';
		else if (x == 1)
			cout << 0 << ' ' << 1 << '\n';
		else
			cout << d[x - 1] << ' ' << d[x] << '\n';
	}

	return 0;
}