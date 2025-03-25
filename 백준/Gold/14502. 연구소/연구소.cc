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

int n, m;
int visited[9][9] = {0};

int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 연구소는 n*m인 직사각형으로 나타낼 수 있다.
    // 연구소는 빈 칸, 벽으로 이루어져 있다.

    // 일부 칸은 바이러스가 존재. 상하좌우로 모두 퍼져나갈 수 있다.
    // 새로 세울 수 있는 벽의 개수는 3개이며, 꼭 3개를 세워야한다.

    // 벽을 세우는 거 보니까 3차원 배열 써야겠지?

    // 0: 빈 칸, 1: 벽, 2: 바이러스

    cin >> n >> m;
    vector<vector<int> > arr(n, vector<int>(m));
    vector<vector<int> > cpy_arr(n, vector<int>(m));
    // 경우의 수를 저장할 공간
    vector<pair<int, int> > no_wall;
    queue<pair<int, int> > q;
    int answer = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (!arr[i][j]) {
                no_wall.push_back({i, j});
            }
        }
    }

    // 해결해야 하는 것은?
    // 벽을 3개를 모두 세우는 경우의 수를 만드는 것이다.

    // 1. 바이러스, 벽이 아닌 좌표 값을 조합으로 뽑는다.(MAX 64 C 3)
    vector<int> masking(no_wall.size(), 1);

    for (int i = 0; i < 3; i++) {
        masking[i] = 0;
    }

    // 2. 벽을 세우고 bfs를 한다.
    do {
        int temp_cnt = 0;
        // 깊은 복사
        copy(arr.begin(), arr.end(), cpy_arr.begin());
        // 방문 배열 초기화
        fill_n(visited[0], 81, 0);

        for (int i = 0; i < masking.size(); i++) {
            // 해당되는 조합일 때
            if (!masking[i]) {
                cpy_arr[no_wall[i].first][no_wall[i].second] = 1;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                //바이러스에서 시작
                if (cpy_arr[i][j] == 2 && !visited[i][j]) {
                    q.push({i, j});
                    visited[i][j] = 1;
                    while (!q.empty()) {
                        int y = q.front().first;
                        int x = q.front().second;
                        q.pop();

                        for (int i = 0; i < 4; i++) {
                            int ny = y + dy[i];
                            int nx = x + dx[i];

                            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                            if (cpy_arr[ny][nx] == 1 || visited[ny][nx] == 1) continue;

                            cpy_arr[ny][nx] = 2;
                            visited[ny][nx] = 1;
                            q.push({ny, nx});
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!cpy_arr[i][j])
                    temp_cnt++;
            }
        }
        answer = max(temp_cnt, answer);
        // 요기 안에서 bfs 할 거임
    } while (next_permutation(masking.begin(), masking.end()));

    cout << answer << '\n';

    return 0;
}
