#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <queue>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#define ll long long

using namespace std;

int arr[41][41];

// 90도 회전
void rotate(vector<vector<int>>& arr) {
	vector<vector<int>> tmp(arr[0].size(), vector<int>(arr.size(), 0));
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			tmp[j][arr.size() - 1 - i] = arr[i][j];
		}
	}
	arr = tmp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	while (k--) {
		int v, h;
		cin >> v >> h;

		// 입력은 단 1회
		vector<vector<int>> base(v, vector<int>(h));
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < h; j++) {
				cin >> base[i][j];
			}
		}

		bool flag = false;

		// 최대 4번 회전
		for (int r = 0; r < 4; r++) {
			int row = base.size();
			int col = base[0].size();

			bool pasted = false;
			for (int i = 0; i <= n - row; i++) {
				for (int j = 0; j <= m - col; j++) {
					bool canPaste = true;
					for (int x = 0; x < row; x++) {
						for (int y = 0; y < col; y++) {
							if (base[x][y] && arr[i + x][j + y]) {
								canPaste = false;
								break;
							}
						}
						if (!canPaste) break;
					}
					if (canPaste) {
						for (int x = 0; x < row; x++) {
							for (int y = 0; y < col; y++) {
								if (base[x][y]) arr[i + x][j + y] = 1;
							}
						}
						pasted = true;
						break;
					}
				}
				if (pasted) break;
			}
			if (pasted) {
				flag = true;
				break;
			}
			// 회전
			rotate(base);
		}
	}

	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j]) answer++;
		}
	}
	cout << answer << '\n';
	return 0;
}