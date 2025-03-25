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

using namespace std;

int n, m;
int r, c, d;
int arr[51][51] = {0};
int visited[51][51] = {0};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    cin >> r >> c >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int cnt = 0;
    queue<pair<int, int> > q;

    q.push({r, c});

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        if (!visited[y][x]) {
            visited[y][x] = 1;
            cnt++;
        }

        bool flag = false;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 1 || nx < 1 || ny >= n - 1 || nx >= m - 1) continue;
            if (visited[ny][nx] || arr[ny][nx] == 1) continue;

            flag = true;
        }

        if (flag) {
            if (d == 0) {
                d = 3;
            } else {
                d--;
            }

            if (!visited[y + dy[d]][x + dx[d]] && !arr[y + dy[d]][x + dx[d]]) {
                q.push({y + dy[d], x + dx[d]});
            } else {
                q.push({y, x});
            }
        } else {
            if (!arr[y - dy[d]][x - dx[d]])
                q.push({y - dy[d], x - dx[d]});
            else {
                break;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}
