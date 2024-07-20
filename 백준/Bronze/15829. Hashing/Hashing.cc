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

	for (int i = 0; i < n; i++) {
		ans += (target[i] - 'a' + 1) * pow(31,i) ;
		ans %= 1234567891;
	}
	
	cout << ans;

	return 0;
}