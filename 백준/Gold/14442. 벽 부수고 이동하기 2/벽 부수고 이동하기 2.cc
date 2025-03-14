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

struct wall {
    int destroy, y, x;
};

char arr[1001][1001] = { 0 };
int visited[11][1001][1001] = { 0 };

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0, 1, -1 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k, ans = 1000001;
    queue<wall> q;

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;

        for (int j = 0; j < m; j++) {
            arr[i][j] = temp[j];
        }
    }



    q.push({ 0,0,0 });
    visited[0][0][0] = 1;

    while (!q.empty()) {
        wall cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            int destroy = cur.destroy;

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            
            // arr[ny][nx] == 0 && !visited[destroy][ny][nx]는 가능한 경우
            if ((arr[ny][nx] == '0') && !visited[destroy][ny][nx]) {
                visited[destroy][ny][nx] = visited[destroy][cur.y][cur.x] + 1;
                q.push({ destroy, ny,nx });
            }

            // 벽이 있을 때 가능한 경우
            // if(arr[ny][nx] == 1)
            // k개 이상의 벽을 부수지 않고, 그 경우 방문하지 않았을 때
            //  if(destroy+1 <= k && !visited[destroy+1][ny][nx])
            if ((arr[ny][nx] == '1') && (destroy + 1 <= k) && !visited[destroy+1][ny][nx]) {
                visited[destroy+1][ny][nx] = visited[destroy][cur.y][cur.x] + 1;
                q.push({ destroy + 1, ny, nx });
            }
        }
    }

    for (int i = 0; i <= k; i++) {
        if (visited[i][n - 1][m - 1]) {
            ans = min(ans, visited[i][n - 1][m - 1]);
        }
    }

    if (ans == 1000001)
        cout << -1 << '\n';
    else
        cout << ans << '\n';

    return 0;
}