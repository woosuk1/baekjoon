#include<iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <queue>
#include <set>
#include <cmath>
#include <stack>
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    while (1) {
        int n;

        cin >> n;

        if (n == 0) break;

        int input;

        long long int Max = 0;

        // 1: 높이, 2: 시작 인덱스
        stack<pair<int, int> > stk;

        for (int i = 0; i < n; i++) {
            cin >> input;

            // push 할 인덱스
            int push_start_idx = i;

            // flush 타임 (stack에 있는 값이 input보다 클 때)
            while (!stk.empty() && stk.top().first >= input) {
                int cal_idx = i - stk.top().second;
                Max = max(Max, 1LL * stk.top().first * cal_idx);
                push_start_idx = stk.top().second;
                stk.pop();
            }

            stk.push(make_pair(input, push_start_idx));
        }

        while (!stk.empty()) {
            int cal_idx = n - stk.top().second;

            Max = max(Max, 1LL * stk.top().first * cal_idx);

            stk.pop();
        }

        cout << Max << "\n";
    }
    return 0;
}
