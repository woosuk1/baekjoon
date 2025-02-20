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
int visited[1001][1001] = {0};
int real_visited[1001][1001] = {0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, ans = 0, chk = 0, cnt = 0;

    queue<pair<int, int> > q;

    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                q.push({i, j});
            }
            if (arr[i][j] == -1)
                cnt++;
            if (arr[i][j] == 0)
                chk++;
        }
    }

    if (!chk) {
        cout << 0;
        return 0;
    }


    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (visited[ny][nx] || arr[ny][nx] == -1 || arr[ny][nx] == 1) continue;
            visited[ny][nx] = 1;
            arr[ny][nx] = arr[y][x] + 1;
            // ans = max(ans, arr[ny][nx]);
            q.push({ny, nx});
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, arr[i][j]);

            if (arr[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }
    }

    cout << ans - 1 << '\n';

    return 0;
}
