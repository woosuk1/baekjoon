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

struct info {
    // 좌표, 이전방향, red, blue인지
    int redY, redX, dir;
    int blueY, blueX, cnt = 0;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, ans = 11;

    cin >> n >> m;

    vector<vector<char> > arr(n, vector<char>(m));
    queue<info> q;

    info init;

    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;

        for (int j = 0; j < m; j++) {
            arr[i][j] = temp[j];
            if (arr[i][j] == 'R') {
                init.redY = i;
                init.redX = j;
                init.dir = -1;
            }
            if (arr[i][j] == 'B') {
                init.blueY = i;
                init.blueX = j;
            }
        }
    }

    q.push(init);

    while (!q.empty()) {
        int redY = q.front().redY;
        int redX = q.front().redX;
        int blueY = q.front().blueY;
        int blueX = q.front().blueX;
        int dir = q.front().dir;
        int cnt = q.front().cnt;
        q.pop();

        // 10번 이미 돈 거는 넘어가자
        if (cnt == 10)
            continue;

        for (int i = 0; i < 4; i++) {
            // 방향이 같을 때 넘어간다.
            if (i == dir)
                continue;
            // 방향 정해짐
            int nRedY = redY;
            int nRedX = redX;
            int nBlueY = blueY;
            int nBlueX = blueX;

            bool redFlag = false;
            bool blueFlag = false;

            // 벽을 만날 때까지
            while (arr[nRedY + dy[i]][nRedX + dx[i]] != '#') {
                nRedY = nRedY + dy[i];
                nRedX = nRedX + dx[i];
                if (arr[nRedY][nRedX] == 'O') {
                    redFlag = true;
                }
            }

            // 벽을 만날 때까지
            while (arr[nBlueY + dy[i]][nBlueX + dx[i]] != '#') {
                nBlueY = nBlueY + dy[i];
                nBlueX = nBlueX + dx[i];
                if (arr[nBlueY][nBlueX] == 'O') {
                    blueFlag = true;
                }
            }

            if (blueFlag) {
                if (!redFlag) {
                    continue;
                }
            }

            // 빨간 구슬이 빠졌을 때
            if (redFlag) {
                // 파란 구슬이 빠지지 않았을 때 break
                if (!blueFlag) {
                    ans = cnt + 1;
                    cout << ans << '\n';
                    return 0;
                }
                // 둘 다 빠졌을 때? 안됨
                continue;
            }

            // 둘의 좌표가 같을 때
            if (nRedY == nBlueY && nRedX == nBlueX) {
                int tempRed = abs(nRedY - redY) + abs(nRedX - redX);
                int tempBlue = abs(nBlueY - blueY) + abs(nBlueX - blueX);

                // 빨간 구슬의 거리가 더 멀 때
                if (tempRed > tempBlue) {
                    nRedY = nRedY - dy[i];
                    nRedX = nRedX - dx[i];
                } else {
                    nBlueY = nBlueY - dy[i];
                    nBlueX = nBlueX - dx[i];
                }
            }

            q.push({nRedY, nRedX, i, nBlueY, nBlueX, cnt + 1});
        }
    }

    cout << -1 << '\n';

    return 0;
}
