#include<iostream>
#include <cstdio>
#include <algorithm> // for max
#include <vector>
#include <string>
#include <map>
#include <limits.h>
#include <queue>

using namespace std;

bool visited[101][101];
bool visited2[101][101];

vector<vector <char>> arr;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int n;

// 적록색약이 아닌 경우
void bfs(int startY, int startX) {

	// 같아야 하는 변수
	char target = arr[startY][startX];

	queue<pair<int, int>> q;

	visited[startY][startX] = true;
	
	q.push(make_pair(startY,startX));

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n || arr[ny][nx] != target || visited[ny][nx]) {
				continue;
			}
			visited[ny][nx] = true;
			q.push(make_pair(ny, nx));
		}
	}
}

// 적록색약인 경우 (빨 = 초)
void bfs2(int startY, int startX) {

	// 같아야 하는 변수
	char target = arr[startY][startX];

	bool flag = false;

	// 빨강, 초록 일시 flag 활성화
	if (target == 'R' || target == 'G') {
		flag = true;
	}

	queue<pair<int, int>> q;

	visited[startY][startX] = true;

	q.push(make_pair(startY, startX));

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!flag) {
				if (nx < 0 || ny < 0 || nx >= n || ny >= n || arr[ny][nx] != target || visited2[ny][nx]) {
					continue;
				}
				visited2[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
			else {
				if (nx < 0 || ny < 0 || nx >= n || ny >= n || arr[ny][nx] == 'B' || visited2[ny][nx]) {
					continue;
				}
				visited2[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int answer1 = 0, answer2 = 0;

	cin >> n;

	arr.resize(n);

	string alpha;

	for (int i = 0; i < n; i++) {

		arr[i].resize(n);

		cin >> alpha;

		for (int j = 0; j < n; j++) {
			arr[i][j] = alpha[j];
		}
	}


	// 한 번 돌 때 2번 돌 수 있도록
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				bfs(i, j);
				answer1++;
			}
			if (!visited2[i][j]) {
				bfs2(i, j);
				answer2++;
			}
		}
	}

	cout << answer1 << ' ' << answer2 << '\n';

    return 0;
}
