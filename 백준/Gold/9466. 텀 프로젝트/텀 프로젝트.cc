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

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin >> t;

    while (t--) {
        int n;

        cin >> n;

        vector<int> arr(n + 1);
        vector<int> visited(n + 1);
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0) {
                int cur_v = i;

                while (1) {
                    visited[cur_v] = i;
                    cur_v = arr[cur_v];

                    // 이번 방문에서 지나간 학생에 도달했을 경우
                    if (visited[cur_v] == i) {
                        // 사이클에 들어갈 학생들
                        while (visited[cur_v] != -1) {
                            visited[cur_v] = -1;
                            cur_v = arr[cur_v];
                        }
                        break;
                    }
                    // 이전 방문에서 지나간 학생에 도달했을 때는 break
                    if (visited[cur_v] != 0) break;
                }
            }
        }

        for (int j = 1; j < n + 1; j++) {
            if (visited[j] != -1)
                ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}
