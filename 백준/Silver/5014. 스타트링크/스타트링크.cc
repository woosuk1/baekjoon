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

int visited[2000001] = { 0 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int f, s, g, u, d;
    queue<int> q;

    cin >> f >> s >> g >> u >> d;

    q.push(s);
    visited[s] = 1;
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x == g) {
            cout << visited[x] -1;
            return 0;
        }

        if (x + u <= f && !visited[x + u] && u > 0) {
            q.push(x + u);
            visited[x + u] = visited[x] + 1;
        }
        if (x - d >= 1 && !visited[x - d] && d > 0) {
            q.push(x - d);
            visited[x - d] = visited[x] + 1;
        }
    }

    cout << "use the stairs";

    return 0;
}