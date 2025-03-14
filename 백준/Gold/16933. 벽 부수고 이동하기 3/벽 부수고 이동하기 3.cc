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
    int destroy, is_night, y, x;
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

    q.push({ 0,0,0,0 });
    visited[0][0][0] = 1;

    while (!q.empty()) {
        wall cur = q.front();

        //cout << "destroy: " << cur.destroy << " is_night: " << cur.is_night << "\ny: " << cur.y << " x: " << cur.x << '\n';

        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            int destroy = cur.destroy;
            int is_night = cur.is_night;

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

            // arr[ny][nx] == 0 && !visited[destroy][ny][nx]는 가능한 경우
            if ((arr[ny][nx] == '0') && !visited[destroy][ny][nx]) {
                visited[destroy][ny][nx] = visited[destroy][cur.y][cur.x] + 1;
                q.push({ destroy, !is_night, ny,nx });
                //cout << "1. destroy: " << destroy << " visited: " << visited[destroy][ny][nx] << " ny: " << ny << " nx: " << nx << '\n';
                //cout << " cury: " << cur.y << " curx: " << cur.x << '\n';
                //cout << "is night: " << q.front().is_night << '\n';
            }
        }

        bool flag = false;

        for (int i = 0; i < 4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            int destroy = cur.destroy;
            int is_night = cur.is_night;
           

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

            if ((arr[ny][nx] == '1') && (destroy + 1 <= k) && !visited[destroy + 1][ny][nx]) {
                // 낮일 때(부술 수 있을 때)
                if (is_night ) {
                    if (!flag) {
                        visited[destroy][cur.y][cur.x] = visited[destroy][cur.y][cur.x] + 1;
                    }
                    q.push({ destroy, !is_night, cur.y,cur.x });
                    flag = true;
                    //cout << "3. destroy: " << destroy << " visited: " << visited[destroy][cur.y][cur.x] << " cury: " << cur.y << " curx: " << cur.x << '\n';
                }
                else {
                    visited[destroy + 1][ny][nx] = visited[destroy][cur.y][cur.x] + 1;
                    q.push({ destroy + 1,!is_night, ny, nx });
                    //cout << "2. destroy: " << destroy + 1 << " visited: " << visited[destroy + 1][ny][nx] << " ny: " << ny << " nx: " << nx << '\n';
                }
            }
        }

    }

    //cout << '\n';

    for (int i = 0; i <= k; i++) {
        //cout << "i: " << i << "visited: " << visited[i][n - 1][m - 1] << '\n';
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