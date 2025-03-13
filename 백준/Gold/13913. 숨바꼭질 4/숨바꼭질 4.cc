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

pair<int, int> visited[200002] = { {0,0} };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    queue<int> q;

    cin >> n >> k;

    // 동생 위치가 수빈이보다 앞에 있을 때
    if (k <= n) {
        cout << n - k << '\n' << n << ' ';
        while (k != n) {
            cout << --n << ' ';
        }
        return 0;
    }

    // 1. 초기화 시에는 (1,본인 좌표)를 넣어서 방문 처리를 해준다.
    //    종료 조건이 될 값이다.

    visited[n] = { 1,n };
    q.push(n);

    // 2. bfs를 돌면서 (거리, 현재 좌표)를 넣어서 방문 처리를 해준다.
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur - 1 >= 0 && !visited[cur-1].first ) {
            visited[cur - 1] = { visited[cur].first + 1, cur };
            q.push(cur-1);
        }

        if (!visited[cur + 1].first) {
            visited[cur + 1] = { visited[cur].first + 1, cur };
            q.push(cur+1);
        }

        if (2 * cur <= 200000 && !visited[2 * cur].first) {
            visited[cur * 2] = { visited[cur].first + 1, cur };
            q.push(cur * 2);
        }

        if (visited[k].first)
            break;
    }

    // 3. visited[k].first -1 출력 후
    //    역으로 배열을 돈다.
    //    n == visited[k].second 일 시 출력 후 break
    cout << visited[k].first - 1 << '\n';

    vector<int> arr;

    arr.push_back(k);

    while (n != visited[k].second) {
        arr.push_back(visited[k].second);
        k = visited[k].second;
    }

    cout << n << ' ';

    for (int i = arr.size() - 1; i >= 0; i--) {
        cout << arr[i] << ' ';
    }

    return 0;
}