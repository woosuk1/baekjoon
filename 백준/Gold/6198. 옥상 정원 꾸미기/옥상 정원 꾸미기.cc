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

    int n;

    // 입력값 받을 배열
    int arr[80002];
    // 정답 배열
    // int answer[80002] = {0};
    long long int answer = 0;
    // 스택
    stack<pair<int, int> > stk;

    cin >> n;

    stk.push(make_pair(1087654321, 0));

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        while (stk.top().first <= arr[i]) {
            answer += i - stk.top().second - 1;
            stk.pop();
        }
        // answer[i] = stk.top().second;
        stk.push(make_pair(arr[i], i));
        // cout << "i: " << i << ", answer: " << answer << " ";
    }

    while (stk.top().first < 1087654321) {
        answer += n - stk.top().second;
        stk.pop();
    }

    cout << answer << " ";

    return 0;
}
