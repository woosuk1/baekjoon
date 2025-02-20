#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <limits.h>
#include <queue>
#include <set>
#include <math.h>
#include <stack>
#include <deque>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int arr[1001][1001] = {0};
int fire_visited[1001][1001] = {0};
int visited[1001][1001] = {0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, ans = 99999999;

    pair<int, int> fire;
    pair<int, int> jihun;

    cin >> n >> m;
    cin.ignore();

    queue<pair<int, int> > q;
    vector<string> arr_str(n);

    for (int i = 0; i < n; i++) {
        getline(cin, arr_str[i]);
        for (int j = 0; j < m; j++) {
            if (arr_str[i][j] == '#') {
                arr[i][j] = -1;
            } else if (arr_str[i][j] == '.') {
                arr[i][j] = 0;
            } else if (arr_str[i][j] == 'J') {
                arr[i][j] = 1;
                jihun = {i, j};
            } else {
                arr[i][j] = 2;
                q.push({i, j});
                fire_visited[i][j] = 1;
            }
        }
    }


    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (fire_visited[ny][nx] || arr[ny][nx] == -1) continue;

            fire_visited[ny][nx] = fire_visited[y][x] + 1;
            q.push({ny, nx});
        }
    }

    q.push(jihun);
    visited[jihun.first][jihun.second] = 1;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                ans = min(ans, visited[y][x] + 1);
                continue;
            }
            if (visited[ny][nx] || arr[ny][nx] == -1 || arr[ny][nx] == 2)
                continue;
            if (fire_visited[ny][nx] > visited[y][x] + 1 || !fire_visited[ny][nx]) {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }

    if (ans != 99999999)
        cout << ans - 1;
    else
        cout << "IMPOSSIBLE";

    return 0;
}
