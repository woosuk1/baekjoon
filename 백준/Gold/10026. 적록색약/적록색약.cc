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
#include <tuple>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    int non_cnt = 0;
    int cnt = 0;
    queue<pair<int, int> > q;

    cin >> n;

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int> > non_visited(n, vector<int>(arr[0].size()));
    vector<vector<int> > visited(n, vector<int>(arr[0].size()));

    // 비 적록색약
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            if (non_visited[i][j]) continue;

            non_cnt++;

            q.push({i, j});
            non_visited[i][j] = 1;

            while (!q.empty()) {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();
                for (int l = 0; l < 4; l++) {
                    int ny = y + dy[l];
                    int nx = x + dx[l];
                    if (ny < 0 || ny >= n || nx < 0 || nx >= arr[0].size()) continue;
                    if (non_visited[ny][nx]) continue;
                    if (arr[i][j] == 'R') {
                        if (arr[ny][nx] != 'R') continue;
                    } else if (arr[i][j] == 'B') {
                        if (arr[ny][nx] != 'B') continue;
                    } else if (arr[i][j] == 'G') {
                        if (arr[ny][nx] != 'G') continue;
                    }
                    q.push({ny, nx});
                    non_visited[ny][nx] = 1;
                }
            }
        }
    }
    // 적록색약
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            if (visited[i][j]) continue;
            cnt++;
            q.push({i, j});
            visited[i][j] = 1;
            while (!q.empty()) {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();
                for (int l = 0; l < 4; l++) {
                    int ny = y + dy[l];
                    int nx = x + dx[l];
                    if (ny < 0 || ny >= n || nx < 0 || nx >= arr[0].size()) continue;
                    if (visited[ny][nx]) continue;
                    if (arr[i][j] == 'R' || arr[i][j] == 'G') {
                        if (arr[ny][nx] == 'B') continue;
                    } else if (arr[i][j] == 'B') {
                        if (arr[ny][nx] != 'B') continue;
                    }
                    q.push({ny, nx});
                    visited[ny][nx] = 1;
                }
            }
        }
    }

    cout << non_cnt << ' ' << cnt;

    return 0;
}
