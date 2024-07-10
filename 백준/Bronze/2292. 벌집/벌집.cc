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
	
	int n, ans = 1;

	cin >> n;
	
	// n = 1일 때
	if (n == 1) {
		cout << 1;
		return 0;
	}

	int i = 1;

	while (1) {
		if (n <= 1 + 3 * i * (i + 1)) {
			ans = i;
			break;
		}
		
		i++;
	}

	cout << ans+1;
	return 0;
}