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
#include <string.h>

using namespace std;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};
int arr[101][101] = {0};
int visited[101][101] = {0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, cnt = 1, ans = 10001;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    queue<pair<int, int> > q;
    // 섬 구분하기(n^4) 최대 1억
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && arr[i][j] != 0) {
                q.push({i, j});
                visited[i][j] = 1;
                arr[i][j] = cnt;
                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int ny = y + dy[k];
                        int nx = x + dx[k];

                        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                        if (visited[ny][nx] || !arr[ny][nx]) continue;

                        q.push({ny, nx});
                        visited[ny][nx] = 1;
                        arr[ny][nx] = cnt;
                    }
                }
                cnt++;
            }
        }
    }

    // 최단 거리 구하기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 섬이면서 방문 하지 않은 배열일 때
            if (arr[i][j] != 0) {
                q = queue<pair<int, int> >();
                // 시작 섬의 value
                int rem = arr[i][j];
                bool flag = true;
                // visited 배열 초기화
                // fill(&visited[0][0], &visited[0][0] + n * n, 0);
                memset(visited, 0, sizeof(visited));

                q.push({i, j});
                visited[i][j] = 1;

                while (!q.empty()) {
                    if (!flag)
                        break;
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int ny = y + dy[k];
                        int nx = x + dx[k];

                        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

                        // 다른 섬일 때
                        if (arr[ny][nx] && arr[ny][nx] != rem) {
                            ans = min(ans, visited[y][x] - 1);
                            flag = false;
                            break;
                        }
                        if (visited[ny][nx] || arr[ny][nx] == rem) continue;

                        q.push({ny, nx});
                        visited[ny][nx] = visited[y][x] + 1;
                    }
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
