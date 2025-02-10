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

    int n, ans = 0;

    cin >> n;

    while (n--) {
        string s;
        stack<char> stk;

        cin >> s;

        for (char i: s) {
            if (stk.empty())
                stk.push(i);
            else {
                if (stk.top() == i) {
                    stk.pop();
                } else {
                    stk.push(i);
                }
            }
        }

        if (stk.empty()) {
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}

