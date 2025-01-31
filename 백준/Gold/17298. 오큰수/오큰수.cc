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
    // int arr[1000002];

    // int answer[1000002] = {0};
    // 스택
    stack<pair<int, int> > stk;

    cin >> n;

    vector<int> arr(n + 1, -1); // 초기화하기 위해 가변배열 선언
    vector<int> answer(n + 1, -1); // 초기화하기 위해 가변배열 선언

    stk.push(make_pair(1087654321, 0));

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        while (stk.top().first < arr[i]) {
            answer[stk.top().second] = arr[i];
            stk.pop();
        }
        stk.push(make_pair(arr[i], i));
    }

    // while (stk.top().first < 1087654321) {
    //     answer += n - stk.top().second;
    //     stk.pop();
    // }

    for (int i = 1; i <= n; i++) {
        cout << answer[i] << " ";
    }

    return 0;
}
