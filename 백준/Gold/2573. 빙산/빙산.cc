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

// int arr[301][301] = {0};
// int cpy_arr[301][301] = {0};
// int visited[301][301] = {0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, ans = 0;

    cin >> n >> m;

    vector<vector<int> > arr(n, vector<int>(m));
    vector<vector<int> > cpy_arr(n, vector<int>(m));
    map<pair<int, int>, int> mp;
    queue<pair<int, int> > q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            cpy_arr[i][j] = arr[i][j];
            if (arr[i][j]) {
                mp[make_pair(i, j)] = arr[i][j];
            }
        }
    }

    int chk = mp.size();

    while (1) {
        vector<vector<int> > visited(n, vector<int>(m));
        q.push({mp.begin()->first});
        visited[mp.begin()->first.first][mp.begin()->first.second] = 1;
        int cnt = 1;
        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                if (!cpy_arr[ny][nx] && arr[y][x]) {
                    arr[y][x]--;
                    if (--mp[make_pair(y, x)] == 0)
                        mp.erase(make_pair(y, x));
                }

                if (visited[ny][nx] || !arr[ny][nx]) continue;

                q.push({ny, nx});
                visited[ny][nx] = visited[y][x] + 1;
                cnt++;
            }
        }

        if (cnt != chk) {
            cout << ans;
            return 0;
        }

        if (mp.empty()) {
            cout << 0;
            return 0;
        }

        chk = mp.size();
        ans++;

        copy(arr.begin(), arr.end(), cpy_arr.begin());
        /*
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << arr[i][j] << ' ';
            }
            cout << '\n';
        }

        cout << "\n\n";
    */
    }

    return 0;
}
