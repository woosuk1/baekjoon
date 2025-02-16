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

    string s;
    stack<char> stk;
    cin >> s;

    int save = 1, answer = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            save *= 2;
            stk.push(s[i]);
        } else if (s[i] == '[') {
            save *= 3;
            stk.push(s[i]);
        } else if (s[i] == ')') {
            if (stk.empty() || stk.top() != '(') {
                cout << 0;
                return 0;
            }
            if (s[i - 1] == '(') {
                answer += save;
            }
            stk.pop();
            save /= 2;
        } else if (s[i] == ']') {
            if (stk.empty() || stk.top() != '[') {
                cout << 0;
                return 0;
            }
            if (s[i - 1] == '[') {
                answer += save;
            }
            stk.pop();
            save /= 3;
        } else {
            cout << 0;
            return 0;
        }
    }

    if (stk.empty()) {
        cout << answer;
    }
    else {
        cout << 0;
    }

    return 0;
}
