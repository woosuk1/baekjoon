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

int n, cnt = 0;

int visited[41] = {0};
// 좌대각선 방문 배열
int visited2[41] = {0};
// 우대각선 방문 배열
int visited3[41] = {0};


// cur_col는 현재 열의 위치다.
void dfs(int cur_col) {
    if (cur_col == n) {
        cnt++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] || visited2[i + cur_col] || visited3[cur_col - i + n - 1]) continue;
        visited[i] = 1;
        visited2[i + cur_col] = 1;
        visited3[cur_col - i + n - 1] = 1;
        dfs(cur_col + 1);
        visited[i] = 0;
        visited2[i + cur_col] = 0;
        visited3[cur_col - i + n - 1] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    dfs(0);

    cout << cnt << '\n';

    return 0;
}
