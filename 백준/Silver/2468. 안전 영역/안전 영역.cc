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

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

// int arr[101][101] = {0};
// int visited[101][101] = {0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, cnt = 0;

    cin >> n;

    vector<vector<int> > arr(n, vector<int>(n));
    queue<pair<int, int> > q;
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            mp[arr[i][j]]++;
        }
    }

    mp.insert({0, 1});

    for (auto l: mp) {
        int tmp_cnt = 0;
        vector<vector<int> > visited(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && arr[i][j] > l.first) {
                    q.push({i, j});
                    visited[i][j] = 1;
                    tmp_cnt++;
                    while (!q.empty()) {
                        int y = q.front().first;
                        int x = q.front().second;
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int ny = y + dy[k];
                            int nx = x + dx[k];

                            if (nx < 0 || ny >= n || ny < 0 || ny >= n) continue;
                            if (visited[ny][nx] || arr[ny][nx] <= l.first) continue;
                            q.push({ny, nx});
                            visited[ny][nx]++;
                        }
                    }
                }
            }
        }
        cnt = max(cnt, tmp_cnt);
    }

    cout << cnt;

    return 0;
}
