#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <deque>
#include <climits>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
using namespace std;

using ll = long long;

void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}


int main() {

	init();

	int n;

	cin >> n;

	string target;

	cin >> target;

	ll ans = 0;

	ll temp = 1;

	for (int i = 0; i < n; i++) {
		ans = (ans + (target[i] - 96) * temp) % 1234567891;
		temp = temp * 31 % 1234567891;
	}
	
	cout << ans;

	return 0;
}