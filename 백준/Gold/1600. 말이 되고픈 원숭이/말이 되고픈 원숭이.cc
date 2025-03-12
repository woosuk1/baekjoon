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

int arr[202][202] = { 0 };
int visited[32][202][202] = {0};

// k번 이상이면 4까지만 반복문 돌리기
int dx[12] = { 0,0,-1,1, 2, 2,1,1,-1,-1,-2,-2};
int dy[12] = { 1,-1,0,0, 1,-1,2,-2,2,-2,1,-1};

struct horse {
    int attempt, y, x;
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k, ans = INT_MAX;

    cin >> k;

    int m, n;

    cin >> m >> n;

    queue<horse> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    q.push({ 0,0 ,0});
    visited[0][0][0] = 1;

    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int attempt = q.front().attempt;
        q.pop();

        for (int i = 0; i < 12; i++) {
            if (i == 4 && attempt == k)
                break;
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (arr[ny][nx]) continue;
            // 똑같은 시도 수에 방문한 적이 없을 때(상하좌우)
            if (i<=3 && !visited[attempt][ny][nx]) {
                visited[attempt][ny][nx] = visited[attempt][y][x] + 1;
                q.push({attempt, ny,nx });
            }
            
            // 한번 더 시도한 경우에 방문한 적이 없을 때(말이 이동 시)
            if (i > 3 && !visited[attempt+1][ny][nx]) {
                visited[attempt+1][ny][nx] = visited[attempt][y][x] + 1;
                q.push({attempt+1, ny,nx });
            }
        }
    }

    for (int i = 0; i <= k; i++) {
        if(visited[i][n-1][m-1])
            ans = min(visited[i][n - 1][m - 1], ans);
    }

    if (ans == INT_MAX) {
        cout << -1 << '\n';
    }
    else {
        cout << ans -1 << '\n';
    }

    return 0;
}