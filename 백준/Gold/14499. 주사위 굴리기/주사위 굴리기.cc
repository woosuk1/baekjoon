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

int mp[21][21] = { 0 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 크기가 n*m인 지도가 존재한다.
    // 지도의 r: 동, u: 북
    // 지도의 좌표는 (r,c)로 나타낸다.
    // r: 북쪽부터 떨어진 칸의 갯수, c: 서쪽부터 떨어진 칸의 갯수

    // 주사위는 지도 위에 윗 면이 1이고, 동쪽을 바라보는 방향이 3인 상태로 놓임
    // 놓여져 있는 곳의 좌표는 (x,y)
    // 초기값으로 모든 면은 0

    // solution.
 
    // 그때 시점의 주사위 전개도에서 놀면됨
    // 주사위 인덱스
    // 가로: arr[1][0], arr[1][1], arr[1][2] // 서, 북(윗면), 동
    // 세로: arr[0][1], arr[1][1], arr[2][1], arr[3][1] '' / 윗면 / ''/ 아랫면

    // 초기화
    int arr[4][3] = { 0 };
    // 복사 주사위
    int cpy_arr[4][3] = { 0 };

    // input.
    // 세로크기 n, 가로크기 m, (1<=n,m<=20) 주사위를 놓은 곳의 좌표(x,y), 명령의 개수(1<=k<=1000)
    // n개의 지도에 쓰여 있는 수가 북 -> 남, 서 -> 동
    // 주사위를 놓은 칸에 쓰여 있는 수는 항상 0이다.
    // 지도의 각 칸에 쓰여있는 수는 10미만의 자연수 또는 0이다.

    int n, m, x, y, k;

    cin >> n >> m >> y >> x >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mp[i][j];
        }
    }

    while (k--) {
        int rotate;
        cin >> rotate;

        // 깊은 복사
        copy(&arr[0][0], &arr[0][0] + 12, &cpy_arr[0][0]);

        // 주사위 굴리기
        if (rotate == 1) { //동
            if (x + 1 >= m) {
                continue;
            }
            arr[3][1] = cpy_arr[1][2];
            arr[1][2] = cpy_arr[1][1];
            arr[1][1] = cpy_arr[1][0];
            arr[1][0] = cpy_arr[3][1];
            x++;
        }
        else if (rotate == 2) { //서
            if (x - 1 < 0) {
                continue;
            }
            arr[3][1] = cpy_arr[1][0];
            arr[1][1] = cpy_arr[1][2];
            arr[1][0] = cpy_arr[1][1];
            arr[1][2] = cpy_arr[3][1];
            x--;
        }
        else if (rotate == 3) { //북
            if (y - 1 < 0) {
                continue;
            }
            arr[0][1] = cpy_arr[1][1];
            arr[1][1] = cpy_arr[2][1];
            arr[2][1] = cpy_arr[3][1];
            arr[3][1] = cpy_arr[0][1];
            y--;
        }
        else if (rotate == 4) { //남
            if (y + 1 >= n) {
                continue;
            }
            arr[0][1] = cpy_arr[3][1];
            arr[1][1] = cpy_arr[0][1];
            arr[2][1] = cpy_arr[1][1];
            arr[3][1] = cpy_arr[2][1];
            y++;
        }

        // 주사위 인덱스
        // 가로: arr[1][0], arr[1][1], arr[1][2] // 서, 북(윗면), 동
        // 세로: arr[0][1], arr[1][1], arr[2][1], arr[3][1] '' / 윗면 / ''/ 아랫면

        if (mp[y][x] == 0) {
            mp[y][x] = arr[3][1];
        }
        else {
            arr[3][1] = mp[y][x];
            mp[y][x] = 0;
        }

        cout << arr[1][1] << '\n';

        // 주사위를 굴렸을 때, 
        // if.이동한 칸에 쓰여 있는 수가 0이면,
        // 주사위의 바닥면에 쓰여 있는 수가 칸에 복사됨.-> 바닥칸을 추적해야겠네?
        // else if. 이동한 칸에 쓰인 수가 0이 아닌 경우에는, 
        // 칸에 쓰여진 수가 바닥면으로 복사됨. 칸에 쓰여 있는 수는 0이 됨.

        // output.
        // 주사위가 이동할 때마다 상단에 쓰여 있는 값을 구하는 것.

        // 제한 사항.
        // 주사위는 지도의 바깥으로 이동시킬 수 없다.
        // 만약 바깥으로 이동시키려는 경우에는 해당 명령을 무시해야한다. 출력도 하면 안됨.
    }

    return 0;
}