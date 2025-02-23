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

int dx[8] = {2, 2, -2, -2, 1, -1, 1, -1};
int dy[8] = {1, -1, 1, -1, 2, 2, -2, -2};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin >> t;

    while (t--) {
        int n;
        queue<pair<int, int> > q;
        cin >> n;

        int startX, startY;

        cin >> startX >> startY;

        int goalX, goalY;

        cin >> goalX >> goalY;

        if (startX == goalX && startY == goalY) {
            cout << 0 << '\n';
            continue;
        }

        vector<vector<int> > arr(n, vector<int>(n));
        vector<vector<int> > visited(n, vector<int>(n));

        q.push({startY, startX});
        visited[startY][startX] = 1;

        while (!q.empty()) {
            bool flag = true;

            if (!flag) break;
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for (int i = 0; i < 8; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                if (visited[ny][nx]) continue;
                q.push({ny, nx});
                visited[ny][nx] = visited[y][x] + 1;
                if (ny == goalY && nx == goalX) {
                    flag = false;
                    cout << visited[ny][nx] - 1 << '\n';
                }
            }
        }
    }

    return 0;
}
