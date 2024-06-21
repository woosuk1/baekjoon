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

int n, m, ans = 9999999;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	string temp;

	char chess[8][8] = { {'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'}
	};

	char save[50][50];
	
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) {
			save[i][j] = temp[j];
		}
	}

	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			int count = 0;
			for (int k = 0; k < 8; k++) {
				for (int l = 0; l < 8; l++) {
					if (chess[k][l] != save[i + k][j + l]) {
						count++;
					}
				}
			}
			ans = min(ans, min(count, 64 - count));
		}
	}

	cout << ans;

	return 0;
}