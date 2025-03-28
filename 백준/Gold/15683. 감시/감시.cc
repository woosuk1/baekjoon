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

// cctv 동선
pair<int, int> one[4] = { {1,0}, {0,1}, {0,-1}, {-1,0} };
pair<int, int> two[2][2] = { {{1,0}, {-1,0}}, {{0,-1}, {0,1} } };
pair<int, int> three[4][2] = { {{1,0}, {0,1}}, {{1,0}, {0,-1}}, {{0,-1}, {-1,0} }, {{-1,0}, {0,1}} };
pair<int, int> four[4][3] = { {{1,0}, {0,1}, {-1,0}},{{1,0}, {0,1}, {0,-1}},{{1,0}, {-1,0}, {0,-1}},{{-1,0}, {0,1}, {0,-1}} };
pair<int, int> five[4] = { {1,0}, {0,1}, {0,-1}, {-1,0} };

// cctv 좌표 구해놔야함
vector<pair<int, int>> cctv1;
vector<pair<int, int>> cctv2;
vector<pair<int, int>> cctv3;
vector<pair<int, int>> cctv4;
vector<pair<int, int>> cctv5;

int n, m;
int cnt = 1, answer = 65;

int temp_cnt = 0;

void backtrack(int idx1, int idx2, int idx3, int idx4, int idx5, vector<vector<int>>& arr);
void backtrack2(int idx1, int idx2, int idx3, int idx4, int idx5, vector<vector<int>>& arr);
void backtrack3(int idx1, int idx2, int idx3, int idx4, int idx5, vector<vector<int>>& arr);
void backtrack4(int idx1, int idx2, int idx3, int idx4, int idx5, vector<vector<int>>& arr);
void backtrack5(int idx1, int idx2, int idx3, int idx4, int idx5, vector<vector<int>>& arr);


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // k개의 cctv가 설치되어 있는데, 5가지 종류가 있다.

    // 1번 CCTV는 한 쪽 방향만 감시할 수 있다. 2번과 3번은 두 방향을 감시할 수 있는데, 2번은 감시하는 방향이 서로 반대방향이어야 하고, 
    // 3번은 직각 방향이어야 한다. 4번은 세 방향, 5번은 네 방향을 감시할 수 있다.

    // cctv는 감시할 수 있는 방향에 있는 칸 전체를 감시할 수 있다.
    // 사무실에는 벽이 있는데, cctv는 벽을 통과할 수 없다.
    // cctv는 회전시킬 수 있는데, 회전은 항상 90도 방향으로 해야함

    // 지도에서 0은 빈 칸, 6은 벽, 1~5는 CCTV의 번호이다.

    // cctv의 최대 개수는 8개를 넘지 않는다.

    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                cctv1.push_back({ i,j });
                cnt *= 4;
            }
            else if (arr[i][j] == 2) {
                cctv2.push_back({ i,j });
                cnt *= 2;
            }
            else if (arr[i][j] == 3) {
                cctv3.push_back({ i,j });
                cnt *= 4;
            }
            else if (arr[i][j] == 4) {
                cctv4.push_back({ i,j });
                cnt *= 4;
            }
            else if (arr[i][j] == 5) {
                cctv5.push_back({ i,j });
            }
        }
    }

    // cctv 각각의 경우의 수를 구해서 하나의 반복문에 녹여낸다.
    // 모든 경우의 수를 세기 위한 반복문

    // 구하고 싶은것은 각각의 경우를 어떻게 저장해서 
    // 그때의 경우에 대한 값을 구하는가?
    // 이거 완전... 백트래킹이잖아?

    // 매개변수를 뭘로 두냐하면..
    // cctv1, cctv2, cctv3, cctv4, cctv5 index, arr
    backtrack(0, 0, 0, 0, 0, arr);

    cout << answer << '\n';

    return 0;
}

// 여러 방향으로 갈 때는 따로 해서 돌려서 break 해줘야겠다.
void backtrack(int idx1, int idx2, int idx3, int idx4, int idx5, vector<vector<int>>& arr) {
    if (cctv1.size() == 0) {
        backtrack2(0, 0, 0, 0, 0, arr);
        return;
    }

    if (idx1 < cctv1.size()) {
        // 4가지 경우의 수를 업데이트 한 배열과 idx1+1을 인자로 넘겨준다.
        for (int i = 0; i < 4; i++) {
            vector<vector<int>> cpy_arr(arr);
            int y = cctv1[idx1].first + one[i].second;
            int x = cctv1[idx1].second + one[i].first;
            while (true) {
                if (y < 0 || x < 0 || y >= n || x >= m || arr[y][x] == 6) break;
                cpy_arr[y][x] = 1;
                y = y + one[i].second;
                x = x + one[i].first;
            }
            backtrack(idx1+1, idx2, idx3, idx4, idx5, cpy_arr);
        }
    }
    else {
        backtrack2(idx1, idx2, idx3, idx4, idx5, arr);
        return;
    }
}

void backtrack2(int idx1, int idx2, int idx3, int idx4, int idx5, vector<vector<int>>& arr) {
    if (cctv2.size() == 0) {
        backtrack3(idx1, 0, 0, 0, 0, arr);
        return;
    }
    
    if (idx2 < cctv2.size()) {
        // 4가지 경우의 수를 업데이트 한 배열과 idx1+1을 인자로 넘겨준다.
        for (int i = 0; i < 2; i++) {
            vector<vector<int>> cpy_arr(arr);
            for (int k = 0; k < 2; k++) {
                int y = cctv2[idx2].first + two[i][k].second;
                int x = cctv2[idx2].second + two[i][k].first;
                while (true) {
                    if (y < 0 || x < 0 || y >= n || x >= m || arr[y][x] == 6) break;
                    cpy_arr[y][x] = 1;
                    y = y + two[i][k].second;
                    x = x + two[i][k].first;
                }
            }
            backtrack2(idx1, idx2+1, idx3, idx4, idx5, cpy_arr);
        }
    }
    else {
        backtrack3(idx1, idx2, idx3, idx4, idx5, arr);
        return;
    }
}

void backtrack3(int idx1, int idx2, int idx3, int idx4, int idx5, vector<vector<int>>& arr) {
    if (cctv3.size() == 0) {
        backtrack4(idx1, idx2, 0, 0, 0, arr);
        return;
    }

    if (idx3 < cctv3.size()) {
        // 4가지 경우의 수를 업데이트 한 배열과 idx1+1을 인자로 넘겨준다.
        for (int i = 0; i < 4; i++) {
            vector<vector<int>> cpy_arr(arr);
            for (int k = 0; k < 2; k++) {
                int y = cctv3[idx3].first + three[i][k].second;
                int x = cctv3[idx3].second + three[i][k].first;
                while (true) {
                    if (y < 0 || x < 0 || y >= n || x >= m || arr[y][x] == 6) break;
                    cpy_arr[y][x] = 1;
                    y = y + three[i][k].second;
                    x = x + three[i][k].first;

                }
            }
            backtrack3(idx1, idx2, idx3+1, idx4, idx5, cpy_arr);
        }
    }
    else {
        backtrack4(idx1, idx2, idx3, idx4, idx5, arr);
        return;
    }
}

void backtrack4(int idx1, int idx2, int idx3, int idx4, int idx5, vector<vector<int>>& arr) {
    if (cctv4.size() == 0) {
        backtrack5(idx1, idx2, idx3, 0, 0, arr);
        return;
    }

    if (idx4 < cctv4.size()) {
        // 4가지 경우의 수를 업데이트 한 배열과 idx1+1을 인자로 넘겨준다.
        for (int i = 0; i < 4; i++) {
            vector<vector<int>> cpy_arr(arr);
            for (int k = 0; k < 3; k++) {
                int y = cctv4[idx4].first + four[i][k].second;
                int x = cctv4[idx4].second + four[i][k].first;
                while (true) {
                    if (y < 0 || x < 0 || y >= n || x >= m || arr[y][x] == 6) break;
                    cpy_arr[y][x] = 1;
                    y = y + four[i][k].second;
                    x = x + four[i][k].first;
                }
            }
            backtrack4(idx1, idx2, idx3, idx4+1, idx5, cpy_arr);
        }
    }
    else {
        backtrack5(idx1, idx2, idx3, idx4, idx5, arr);
        return;
    }
}

void backtrack5(int idx1, int idx2, int idx3, int idx4, int idx5, vector<vector<int>>& arr) {
    int temp_answer = 0;

    if (idx5 < cctv5.size()) {
        for (int i = 0; i < 4; i++) {
            int y = cctv5[idx5].first + five[i].second;
            int x = cctv5[idx5].second + five[i].first;
            while (true) {
                if (y < 0 || x < 0 || y >= n || x >= m || arr[y][x] == 6) break;
                arr[y][x] = 1;
                y = y + five[i].second;
                x = x + five[i].first;
            }
        }
        backtrack5(idx1, idx2, idx3, idx4, idx5+1, arr);
    }
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!arr[i][j]) {
                    temp_answer++;
                }
            }
        }
        answer = min(temp_answer, answer);
        return;
    }

}
