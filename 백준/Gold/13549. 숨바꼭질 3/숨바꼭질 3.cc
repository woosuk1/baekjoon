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

int dist[100002] = {0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;

    cin >> n >> k;

    if (n >= k) {
        cout << n - k << '\n';
        return 0;
    }

    queue<int> q;

    q.push(n);
    // 0일 수도 있으니까 나중에 1빼주기
    dist[n] = 1;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x == k) {
            cout << dist[x] - 1 << '\n';
            return 0;
        }

        int tempX = x;
        // 50000까지 모든 값 해주기
        while (tempX <= 50000) {
            if (dist[tempX * 2] != 0)
                break;
            dist[tempX * 2] = dist[x];
            tempX *= 2;
            q.push(tempX);
            if (tempX == k) {
                cout << dist[k] - 1 << '\n';
                return 0;
            }
        }
        if (!dist[x - 1] && x - 1 >= 0) {
            dist[x - 1] = dist[x] + 1;
            q.push(x - 1);
        }
        if (!dist[x + 1]) {
            dist[x + 1] = dist[x] + 1;
            q.push(x + 1);
        }
    }

    cout << dist[k] - 1 << '\n';

    return 0;
}
