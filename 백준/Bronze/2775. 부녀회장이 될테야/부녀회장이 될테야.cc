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
using namespace std;

using ll = long long;

int main() {

	int t;

	cin >> t;

	int arr[15][15] = { 0, };

	for (int j = 1; j <= 14; j++) { //초기 값
		arr[0][j] = j; //누적합
	}

	for (int i = 1; i <= 14; i++) {
		for (int j = 1; j<= 14; j++) { //누적합을 하기 위해..
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	}

	int k, n;

	while (t--) {
		cin >> k >> n;

		cout << arr[k][n] << '\n';
	}

	return 0;
}