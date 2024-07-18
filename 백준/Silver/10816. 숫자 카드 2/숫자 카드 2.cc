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

	int arr[20000010] = { 0, };

	for (int i = 0; i < n; i++) {
		int temp;

		cin >> temp;

		arr[temp + 10000000]++;
	}

	int m;

	cin >> m;

	for (int i = 0; i < m; i++) {
		int temp2;

		cin >> temp2;

		cout << arr[temp2 + 10000000] << ' ';
	}

	return 0;
}