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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int m, n;

	cin >> m >> n;

	vector<int> arr(n + 1);

	arr[1] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = i*2; j <= n; j += i) {
			arr[j] = 1;
		}
	}



	for (int i = m; i <= n; i++) {
		if (arr[i] == 0)
			cout << i << '\n';
	}

	return 0;
}