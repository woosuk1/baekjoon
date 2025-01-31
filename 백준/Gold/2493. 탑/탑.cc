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
    int arr[500002];
    // 정답 배열
    int answer[500002] = {0};
    // 스택
    stack<pair<int, int> > stk;

    cin >> n;

    stk.push(make_pair(987654321, 0));

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        while (stk.top().first < arr[i]) {
            stk.pop();
        }
        answer[i] = stk.top().second;
        stk.push(make_pair(arr[i], i));
        cout << answer[i] << " ";
    }

    return 0;
}
