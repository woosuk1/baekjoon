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

char arr[601][601];
bool visited[601][601];

int answer = 0;
int n, m;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void bfs(int startY, int startX) {
	
	visited[startY][startX] = true;
	queue<pair<int, int>> q;

	q.push(make_pair(startY, startX));

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= 0 && nx >= 0 && ny < n && nx < m && !visited[ny][nx] && arr[ny][nx] != 'X') {
				if (arr[ny][nx] == 'P')
					answer++;
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
	}
}

int main() {

	init();
	
	int startX;
	int startY;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'I') {
				startX = j;
				startY = i;
			}
		}
	}

	bfs(startY, startX);

	if (answer == 0) {
		cout << "TT";
	}
	else {
		cout << answer;
	}


	return 0;
}