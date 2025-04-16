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

//char arr[5][5];
//bool visited[5][5];
//int ans = 0;
//int dy[4] = { 1,-1,0,0 };
//int dx[4] = { 0,0,-1,1 };
//set<vector<pair<int, int>>> check;
//
//// 인자: 방문한 횟수, 임도연파 cnt, 좌표
//void backtrack(int idx, int lim, int y, int x, vector<pair<int,int>>& save) {
////void backtrack(int idx, int lim, int y, int x) {
//    // base point
//    if (idx == 7) {
//        if (lim <= 3) {
//            ans++;
//            check.insert(save);
//        }
//        return;
//    }
//
//    // 동시에 여러 방향 어떻게 가지?
//    for (int i = 0; i < 4; i++) {
//        int ny = y + dy[i];
//        int nx = x + dx[i];
//
//        if (ny < 0 || nx < 0 || ny > 4 || nx > 4) continue;
//        if (visited[ny][nx]) continue;
//
//        visited[ny][nx] = true;
//        save.push_back({ ny,nx });
//        if (arr[ny][nx] == 'Y') {
//            //backtrack(idx + 1, lim + 1, ny, nx);
//            backtrack(idx + 1, lim + 1, ny, nx, save);
//        }
//        else {
//            //backtrack(idx + 1, lim, ny, nx);
//            backtrack(idx + 1, lim, ny, nx, save);
//        }
//        save.pop_back();
//        visited[ny][nx] = false;
//    }
//}
//
//int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//
//    string temp = "";
//
//    for (int i = 0; i < 5; i++) {
//        cin >> temp;
//        for (int j = 0; j < 5; j++) {
//            arr[i][j]= temp[j];
//        }
//    }
//
//    // 백트래킹 하더라도 가지치기 하고 싶은데...
//    // 전체 경우의 수가 어떻게 되지?
//    // 25*4*4*4*4*4*4 = 102400 괜찮을지도
//    for (int i = 0; i < 5; i++) {
//        for (int j = 0; j < 5; j++) {
//            vector<pair<int, int>> for_check;
//            for_check.push_back({ i,j });
//            visited[i][j] = true;
//            if (arr[i][j] == 'Y') {
//                backtrack(1, 1, i,j, for_check);
//                //backtrack(1, 1, i,j);
//            }
//            else {
//                backtrack(1, 0, i, j, for_check);
//                //backtrack(1, 0, i, j);
//            }
//            visited[i][j] = false;
//        }
//    }
//
//
//    //cout << ans << '\n';
//
//    for (auto c : check) {
//        for (auto a : c) {
//            cout << "체크용: " << a.first << ' ' << a.second << '\n';
//        }
//        cout << '\n';
//    }
//    cout << check.size();
//
//    return 0;
//}


int ans = 0;
char board[5][5];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

// 선택된 7개의 좌표(각각 0~24 값 표현)들이 연결되어 있는지 확인하는 함수  
// row = idx / 5, col = idx % 5로 변환하여 5x5 격자에서의 위치를 결정함.
bool isConnected(const vector<int>& comb) {
    bool selected[25] = { false };
    for (int idx : comb)
        selected[idx] = true;

    vector<bool> visited(25, false);
    int count = 0;

    // BFS 시작: comb의 첫 번째 좌표부터 탐색
    queue<int> q;
    q.push(comb[0]);
    visited[comb[0]] = true;
    count++;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        int r = cur / 5, c = cur % 5;
        for (int d = 0; d < 4; d++) {
            int nr = r + dy[d];
            int nc = c + dx[d];
            int nidx = nr * 5 + nc;
            if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue;
            if (!visited[nidx] && selected[nidx]) {
                visited[nidx] = true;
                q.push(nidx);
                count++;
            }
        }
    }
    return (count == 7);
}

// 조합을 재귀적으로 생성하는 함수  
// start: 다음에 고를 좌표의 시작 인덱스, cnt: 현재까지 선택된 좌표의 개수, comb: 현재 조합
void dfsCombination(int start, int cnt, vector<int>& comb) {
    if (cnt == 7) {
        // 선택한 7개 조합의 좌표들이 서로 연결되어 있는지 확인
        if (isConnected(comb)) {
            int yCount = 0;
            for (int idx : comb) {
                int r = idx / 5, c = idx % 5;
                if (board[r][c] == 'Y')
                    yCount++;
            }
            // 조건: 'Y' (임도연파) 가 3명 이하 -> 즉, '이다솜파'가 최소 4명.
            if (yCount <= 3)
                ans++;
        }
        return;
    }
    // 0번부터 24번 인덱스(5x5 격자) 중에서 조합 생성
    for (int i = start; i < 25; i++) {
        comb.push_back(i);
        dfsCombination(i + 1, cnt + 1, comb);
        comb.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 5x5 격자 입력 받기 (각 줄에 5자의 문자열)
    for (int i = 0; i < 5; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < 5; j++) {
            board[i][j] = line[j];
        }
    }

    vector<int> comb;
    dfsCombination(0, 0, comb);

    cout << ans << "\n";

    return 0;
}