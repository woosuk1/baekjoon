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

int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {-1, 1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

struct idx {
    int z, y, x;
};

// char arr[31][31][31];
// int visited[31][31][31] = {0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int h, n, m;

    while (true) {
        cin >> h >> n >> m;

        vector<vector<vector<char> > > arr(h, vector<vector<char> >(n, vector<char>(m)));
        vector<vector<vector<int> > > visited(h, vector<vector<int> >(n, vector<int>(m)));

        idx start{0, 0, 0};
        idx end{0, 0, 0};
        if (h == 0 && n == 0 && m == 0)
            break;

        for (int k = 0; k < h; k++) {
            for (int i = 0; i < n; i++) {
                string temp;
                cin >> temp;
                for (int j = 0; j < m; j++) {
                    arr[k][i][j] = temp[j];
                    if (temp[j] == 'S')
                        start = {k, i, j};
                    if (temp[j] == 'E')
                        end = {k, i, j};
                }
            }
        }

        queue<idx> q;

        q.push(start);
        visited[start.z][start.y][start.x] = 1;

        bool flag = false;

        while (!q.empty()) {
            idx q_front = q.front();
            q.pop();

            for (int i = 0; i < 6; i++) {
                idx chk = {q_front.z + dz[i], q_front.y + dy[i], q_front.x + dx[i]};

                if (chk.x < 0 || chk.x >= m || chk.y < 0 || chk.y >= n || chk.z < 0 || chk.z >= h) continue;
                if (visited[chk.z][chk.y][chk.x] || arr[chk.z][chk.y][chk.x] == '#') continue;

                q.push(chk);
                visited[chk.z][chk.y][chk.x] = visited[q_front.z][q_front.y][q_front.x] + 1;

                if (chk.z == end.z && chk.y == end.y && chk.x && end.x) {
                    flag = true;
                }
            }
        }

        if (flag) {
            cout << "Escaped in " << visited[end.z][end.y][end.x] - 1 << " minute(s)." << '\n';
        } else {
            cout << "Trapped!" << '\n';
        }
    }
    return 0;
}
