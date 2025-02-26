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

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool visited[101][101] = { 0 };
int arr[101][101] = { 0 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, n, k;
    int cnt = 0;
    vector<int> area;

    queue<pair<int, int>> q;

    cin >> m >> n >> k;

    // 이미 있는 직사각형 좌표
    while (k--) {
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;
        
        for (int i = y1; i < y2; i++) {
            for (int j = x1; j < x2; j++) {
                arr[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // 방문하지 않았고, 직사각형 좌표도 아닐 때
            if (!arr[i][j] && !visited[i][j]) {
                q.push({ i,j });
                visited[i][j] = 1;
                cnt++;
                area.push_back(1);
                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    for (int o = 0; o < 4; o++) {
                        int ny = y + dy[o];
                        int nx = x + dx[o];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        // 방문했거나 사각형이 있으면 넘어가기
                        if (visited[ny][nx] || arr[ny][nx]) continue;
                        q.push({ ny,nx });
                        visited[ny][nx] = 1;
                        area[cnt-1]++;
                    }
                }
            }
        }
    }

    cout << cnt << '\n';

    sort(area.begin(), area.end());

    for (int i = 0; i < cnt; i++) {
        cout << area[i] << ' ';
    }

    return 0;
}