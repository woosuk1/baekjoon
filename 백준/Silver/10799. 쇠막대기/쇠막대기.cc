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

    string s;
    stack<char> stk;

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            stk.push(s[i]);
            ans += 1;
        }
        else if (s[i] == ')' && !stk.empty()) {
            //if (stk.top() == '(' && i-1 != ')') {
            if (i >= 1 && s[i-1] == '(') {
                stk.pop();
                ans += stk.size() - 1; // 1은 레이저로 쓴 (
            }
            else {
                stk.pop();
            }
        }
    }

    cout << ans;

    return 0;
}