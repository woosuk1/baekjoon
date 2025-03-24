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

int arr[101][101] = {0};
pair<int, int> visited[101][101];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;

    cin >> n >> k;

    while (k--) {
        int tempY, tempX;
        cin >> tempY >> tempX;
        arr[tempY][tempX] = -2;
    }

    int rotateCnt;

    cin >> rotateCnt;

    int cur = 1, rotate = 0;
    int y = 1, x = 1;
    int tailY = 1, tailX = 1;
    arr[y][x] = 1;

    while (rotateCnt-- > -1) {
        pair<int, char> condition;
        if (rotateCnt != -1) {
            cin >> condition.first >> condition.second;
        }
        bool flag = true;

        while (cur <= condition.first || !condition.first) {
            int ny = y + dy[rotate];
            int nx = x + dx[rotate];

            if (ny > n || nx > n || ny == 0 || nx == 0 || arr[ny][nx] == 1) {
                flag = false;
                break;
            }

            if (arr[ny][nx] != -2) {
                pair<int, int> tempTail = {tailY, tailX};

                arr[tailY][tailX] = 0;
                visited[y][x] = {ny, nx};
                arr[ny][nx] = 1;
                tailY = visited[tempTail.first][tempTail.second].first;
                tailX = visited[tempTail.first][tempTail.second].second;
                visited[tempTail.first][tempTail.second] = {0, 0};
            } else {
                visited[y][x] = {ny, nx};
                arr[ny][nx] = 1;
            }

            y = ny;
            x = nx;
            cur++;
        }
        if (!flag)
            break;

        if (condition.second == 'L') {
            if (rotate == 0) {
                rotate = 3;
            } else {
                rotate--;
            }
        } else {
            if (rotate == 3) {
                rotate = 0;
            } else {
                rotate++;
            }
        }
    }

    cout << cur << '\n';

    return 0;
}
