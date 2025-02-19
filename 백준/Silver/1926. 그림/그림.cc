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

int arr[501][501] = { 0 };
bool visited[501][501] = {};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    queue<pair<int, int>> q;

    int n, m;

    int cnt = 0, Max = 0;

    // 상하좌우
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 1이 있는지와 방문했는지 판별 후 bfs
            if (arr[i][j] == 1 && !visited[i][j]) {
                int tempMax = 0;
                cnt++;
                q.push(make_pair(i,j));
                visited[i][j] = 1;
                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    tempMax++;
                    q.pop();

                    for (int i = 0; i < 4; i++) {
                        int ny = y + dy[i];
                        int nx = x + dx[i];
                        

                        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                        if (visited[ny][nx] || !arr[ny][nx]) continue;
                        q.push({ ny, nx });
                        visited[ny][nx] = 1;
                    }
                }
                Max = max(Max, tempMax);
            }
        }
    }

    if (!cnt)
        cout << "0\n0";
    else
        cout << cnt << '\n' << Max;
    
    return 0;
}