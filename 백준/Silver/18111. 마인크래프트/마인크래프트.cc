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
#include <sstream>

using namespace std;

using ll = long long;

void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main() {

	init();

	int n, m, b;

	cin >> n >> m >> b;

	int arr[501][501];

	int min_time = 999999999, height = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i <= 256; i++) {
		int from_inventory = 0;
		int remove_block = 0;

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				int cur_height = arr[j][k] - i;
				if (cur_height < 0) from_inventory -= cur_height;
				else remove_block += cur_height;
			}
		}
		// inventory 청산 당하지 않았을 때..
		if (remove_block + b >= from_inventory) {
			int this_time = 2 * remove_block + from_inventory;
			if (min_time >= this_time) {
				min_time = this_time;
				height = i;
			}
		}
	}

	cout << min_time << ' ' << height;

	return 0;
}