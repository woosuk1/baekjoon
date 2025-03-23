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

int n;

int answer = 0;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

void move(int cnt, vector<vector<int> > block) {
    if (cnt == 5) {
        int temp_max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp_max = max(temp_max, block[i][j]);
            }
        }
        answer = max(answer, temp_max);
        return;
    }
    // 1. 전체 블록을 상하좌우 중 한 방향으로 이동.
    // -> 방향을 정한 후, 좌우 방향이면 행들이, 상하 방향이면 열들이 이동
    // -> 이때, 모든 원소들에 대해서 한다.
    // -> 좌 방향이면 x = 0, 우 방향이면 x=n-1에 가까운 것 부터 (y: 0 ->n-1)
    // -> 상 방향이면 y =0, 하 방향이면 y =n-1에 가까운 것 부터 (x: 0-> n-1)
    // x or y가 0,n-1을 마주치거나,
    // arr[ny][nx] != 0일 때까지 움직인다.
    // 이때 arr[ny][nx] = arr[y][x]라면,
    // 그리고 합쳐진 적이 없다면 합친다.
    // arr[ny][nx] = pow(arr[ny][nx] ,2), arr[y][x] = 0 break;
    // 합쳤다면 visited[ny][nx] = 1;

    // 5번 이동했다면 break
    // for문을 통해서 최댓값 식별 및 최댓값 저장

    // 깊은 복사할 배열
    vector<vector<int> > cpy_block;
    // 4가지 방향으로 모두 이동시킨 후, 함수 다시 호출하기, 0:우, 1:좌, 2:상, 3:하
    for (int l = 0; l < 4; l++) {
        cpy_block = block;
        vector<vector<int> > sum(n, vector<int>(n));
        // 우좌이동
        if (l < 2) {
            // y:0~n-1
            for (int i = 0; i < n; i++) {
                if (l == 0) {
                    for (int j = n - 1; j >= 0; j--) {
                        if (cpy_block[i][j] != 0) {
                            int x = j;
                            while (true) {
                                // y는 움직일 일이 없다.
                                int nx = x + dx[l];
                                // 범위를 넘어서거나,
                                if (nx >= n) {
                                    break;
                                }
                                // 0이 아닐 때
                                // 가려는 값과, 원래 값이 일치하지 않을 때
                                if (cpy_block[i][nx]) {
                                    if (cpy_block[i][x] != cpy_block[i][nx])
                                        break;
                                }
                                //  합쳐진 값이거나
                                if (sum[i][nx])
                                    break;
                                // 같을 때
                                if (cpy_block[i][x] == cpy_block[i][nx]) {
                                    cpy_block[i][x] = 0;
                                    cpy_block[i][nx] *= 2;
                                    sum[i][nx] = 1;
                                    break;
                                }

                                // 0을 만나서 가고 있을 때
                                cpy_block[i][nx] = cpy_block[i][x];
                                cpy_block[i][x] = 0;
                                x = nx;
                            }
                        }
                    }
                } else {
                    for (int j = 0; j < n; j++) {
                        if (cpy_block[i][j] != 0) {
                            int x = j;
                            while (true) {
                                // y는 움직일 일이 없다.
                                int nx = x + dx[l];
                                // 범위를 넘어서거나, 합쳐진 값이거나
                                if (nx < 0) {
                                    break;
                                }
                                // 0이 아닐 때
                                // 가려는 값과, 원래 값이 일치하지 않을 때
                                if (cpy_block[i][nx]) {
                                    if (cpy_block[i][x] != cpy_block[i][nx])
                                        break;
                                }
                                //  합쳐진 값이거나
                                if (sum[i][nx])
                                    break;
                                // 같을 때
                                if (cpy_block[i][x] == cpy_block[i][nx]) {
                                    cpy_block[i][x] = 0;
                                    cpy_block[i][nx] *= 2;
                                    sum[i][nx] = 1;
                                    break;
                                }

                                // 0을 만나서 가고 있을 때
                                cpy_block[i][nx] = cpy_block[i][x];
                                cpy_block[i][x] = 0;
                                x = nx;
                            }
                        }
                    }
                }
            }
        }
        // 하상이동
        else {
            for (int j = 0; j < n; j++) {
                if (l == 2) {
                    for (int i = n - 1; i >= 0; i--) {
                        if (cpy_block[i][j] != 0) {
                            int y = i;
                            while (true) {
                                // y는 움직일 일이 없다.
                                int ny = y + dy[l];
                                // 범위를 넘어서거나, 합쳐진 값이거나
                                if (ny >= n) {
                                    break;
                                }
                                // 0이 아닐 때
                                // 가려는 값과, 원래 값이 일치하지 않을 때
                                if (cpy_block[ny][j]) {
                                    if (cpy_block[y][j] != cpy_block[ny][j])
                                        break;
                                }
                                // 합쳐진 값..
                                if (sum[ny][j])
                                    break;

                                // 같을 때
                                if (cpy_block[y][j] == cpy_block[ny][j]) {
                                    cpy_block[y][j] = 0;
                                    cpy_block[ny][j] *= 2;
                                    sum[ny][j] = 1;
                                    break;
                                }

                                // 0을 만나서 가고 있을 때
                                cpy_block[ny][j] = cpy_block[y][j];
                                cpy_block[y][j] = 0;
                                y = ny;
                            }
                        }
                    }
                } else {
                    for (int i = 0; i < n; i++) {
                        if (cpy_block[i][j] != 0) {
                            int y = i;
                            while (true) {
                                // y는 움직일 일이 없다.
                                int ny = y + dy[l];

                                // 범위를 넘어서거나, 합쳐진 값이거나
                                if (ny < 0) {
                                    break;
                                }
                                // 0이 아닐 때
                                // 가려는 값과, 원래 값이 일치하지 않을 때
                                if (cpy_block[ny][j]) {
                                    if (cpy_block[y][j] != cpy_block[ny][j])
                                        break;
                                }

                                // 합쳐진 값..
                                if (sum[ny][j])
                                    break;
                                // 같을 때
                                if (cpy_block[y][j] == cpy_block[ny][j]) {
                                    cpy_block[y][j] = 0;
                                    cpy_block[ny][j] *= 2;
                                    sum[ny][j] = 1;
                                    break;
                                }

                                // 0을 만나서 가고 있을 때
                                cpy_block[ny][j] = cpy_block[y][j];
                                cpy_block[y][j] = 0;
                                y = ny;
                            }
                        }
                    }
                }
            }
        }
        move(cnt + 1, cpy_block);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 전체 블록을 상하좌우 네 방향 중 하나로 이동시키는 것
    // 같은 값을 갖는 두 블록이 충돌하면 두 블록은 하나로 합쳐지게 됨.
    // -> 한 번의 이동에서: 이미 합쳐진 블록은 또 다른 블록과 다시 합쳐질 수 없다.
    // -> 똑같은 수가 3개가 있으면 이동하려고 하는 쪽의 칸이 먼저 합쳐진다.
    // 블록이 추가되는 경우는 없다.

    // 최대 5번 이동해서 만들 수 있는 가장 큰 블록의 값을 구하는 프로그램을 작성하시오.

    cin >> n;

    vector<vector<int> > arr(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    // 시간복잡도는 (4^5)1024 * (n^2) 400 * ?

    move(0, arr);

    cout << answer;

    return 0;
}
