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

bool visited[51][51];
int arr[51][51] = { 0 };
int cnt = 0;
int dx_dy[4][2] = { {1,0}, {0,1}, {0,-1}, {-1,0} };
int n, m;

void dfs(int y, int x) {
	if (visited[y][x])
		return;

	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx_dy[i][0];
		int ny = y + dx_dy[i][1];

		if (ny >=  n|| ny < 0 || nx >=m || nx < 0 || !arr[ny][nx])
			continue;
		if (!visited[ny][nx]) {
			dfs(ny, nx);
		}
	}

}

int main() {

	init();
	
	int t;

	// test case 개수
	cin >> t;

	int k;

	while (t--) {
		cin >> m >> n >> k;

		if (m == 1 && n == 1) {
			cout << 1;
			continue;
		}
		//세로, 가로 순
//		vector<vector <int>> arr(n, vector<int>(m));

		for (int i = 0; i < k; i++) {
			int tempX, tempY;

			cin >> tempX >> tempY;

			arr[tempY][tempX] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i][j])
					continue;
				if (arr[i][j] == 1) {
					dfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << '\n';
		cnt = 0;

		for (int i = 0; i < n; i++) {
			memset(visited[i], false, sizeof(bool) * m);
			memset(arr[i], 0, sizeof(int) * m);
		}
	}
	
	return 0;
}