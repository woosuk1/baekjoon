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
#define ll long long
using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int visited[1001][1001][2] = {0};
char arr[1001][1001];

struct wall {
    int y, x, destroy;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    queue<wall> q;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        string temp;
        cin >> temp;
        for (int j = 1; j <= m; j++) {
            arr[i][j] = temp[j - 1];
        }
    }

    q.push({1, 1, 0});
    visited[1][1][0] = 1;

    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int destroy = q.front().destroy;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 1 || ny > n || nx < 1 || nx > m) continue;

            // 1. 벽 부수지 않을 상태 분기
            if (!visited[ny][nx][0] && !destroy && arr[ny][nx] != '1') {
                visited[ny][nx][0] = visited[y][x][0] + 1;
                q.push({ny, nx, 0});
            }

            // 2. 벽 부술 상태 분기
            if (!visited[ny][nx][1]) {
                if (arr[ny][nx] == '1') {
                    if (!destroy) {
                        if (visited[y][x][0]) {
                            visited[ny][nx][1] = visited[y][x][0] + 1;
                            q.push({ny, nx, 1});
                        }
                    }
                } else {
                    if (visited[y][x][1]) {
                        visited[ny][nx][1] = visited[y][x][1] + 1;
                        q.push({ny, nx, 1});
                    }
                }
            }
        }
    }

    if (!visited[n][m][0]) {
        if (!visited[n][m][1])
            cout << -1;
        else
            cout << visited[n][m][1];
    } else {
        if (!visited[n][m][1])
            cout << visited[n][m][0];
        else
            cout << min(visited[n][m][0], visited[n][m][1]);
    }
    return 0;
}
