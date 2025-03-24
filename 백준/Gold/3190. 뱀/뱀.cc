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

// 90도씩 회전하도록, L방향이면 -로 가게 할 것. i<0, i>=n 일 때 조건 해야함.
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 뱀이 사과를 먹으면 뱀 길이가 늘어남
    // 뱀이 벽 또는 자기 자신과 부딪히면 게임이 끝난다.

    // input: 사과의 위치와 뱀의 이동경로가 주어짐!!
    // 보드의 크기: 2<=n<=100 | 사과 개수: 0<=k<=100
    // k개의 줄에는 사과의 줄 위치가 주어짐. (1: y, 2: x), 0,0에는 사과 x
    // 뱀의 방향 변환 횟수 L이 주어짐
    // L은 정수 X와 문자 C로 이루어짐, X는 증가하는 순으로 주어짐
    // 게임 시작으로부터 X초가 '끝난' 뒤에 'L', 'D'로 90도 방향을 회전시킨다.

    int n, k;

    cin >> n >> k;

    while (k--) {
        int tempY, tempX;
        cin >> tempY >> tempX;
        // 사과는 -2로 둘거다
        arr[tempY][tempX] = -2;
    }

    int rotateCnt;

    cin >> rotateCnt;

    int cur = 1, rotate = 0;
    int y = 1, x = 1;
    int tailY = 1, tailX = 1;
    // 뱀이 있는 위치는 1로 지정
    arr[y][x] = 1;
    // visited[1][1] = {1, 2};

    while (rotateCnt-- > -1) {
        pair<int, char> condition;
        if (rotateCnt != -1) {
            cin >> condition.first >> condition.second;
        }
        bool flag = true;
        // cout << "\nrotate: " << rotate << " dy[rotate]: " << dy[rotate] << " dx[rotate]: " << dx[rotate] << '\n';
        // 이동 시 조건: 매 초마다 이동을 함.
        // 1. 먼저 뱀은 몸길이를 늘려 머리를 다음 칸에 위치시킴
        // 2. ny,nx == n-1 or 0 , arr[ny][nx] = "뱀"이면 게임 끝
        // 3. arr[ny][nx] = "사과", arr[ny][nx] = "뱀", visited[y][x] = (ny,nx)
        //     -> 꼬리에는 진행방향이 저장되어야함(그 다음 꼬리)
        // X   ->  만약 y,x의 ny,nx 여러 방향에 사과가 있다면?????? -> 이동경로가 주어짐
        // 4. arr[ny][nx] != "사과"
        //    ->  tailY, tailX = visited[tailY][tailX]의 first, second

        // 아직 주어진 시간에 다다르지 않았을 때
        while (cur <= condition.first || !condition.first) {
            int ny = y + dy[rotate];
            int nx = x + dx[rotate];
            // cout << "cur: " << cur << ' ';
            // cout << "ny: " << ny << " nx: " << nx << '\n';

            // 벽에 부딪히거나, 뱀을 마주쳤을 때
            if (ny > n || nx > n || ny == 0 || nx == 0 || arr[ny][nx] == 1) {
                flag = false;
                break;
            }

            // 사과를 먹지 않았을 때
            if (arr[ny][nx] != -2) {
                pair<int, int> tempTail = {tailY, tailX};

                // 뱀 없애기
                arr[tailY][tailX] = 0;
                visited[y][x] = {ny, nx};
                arr[ny][nx] = 1;
                // 다음 경로가 저장된 꼬리 좌표로 최신화
                tailY = visited[tempTail.first][tempTail.second].first;
                tailX = visited[tempTail.first][tempTail.second].second;
                // 비워주기
                visited[tempTail.first][tempTail.second] = {0, 0};
            } else {
                // cout << "사과 발견: " << "ny: " << ny << " nx: " << nx << '\n';
                visited[y][x] = {ny, nx};
                arr[ny][nx] = 1;
            }

            y = ny;
            x = nx;
            cur++;
        }
        if (!flag)
            break;

        // 다다랐으면, 회전 하기
        // 90도씩 회전하도록, L방향이면 -로 가게 할 것. i<0, i>=n 일 때 조건 해야함.
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
