#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;


int main() {

	int n;

	cin >> n;

	int d[5001] = { 0, };
	
	d[3] = 1;
	d[5] = 1;
	for (int i = 6; i <= n; i++) {
		if (d[i - 3] != 0)
			d[i] = d[i - 3] + 1;
		if (d[i - 5] != 0)
			d[i] = d[i - 5] + 1;
	}

	if (d[n] == 0)
		cout << -1;
	else
		cout << d[n];

	return 0;
}