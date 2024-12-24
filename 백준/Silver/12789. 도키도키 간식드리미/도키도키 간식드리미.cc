#include<iostream>
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

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int n;
    int arr[1001] = { 0 };
    stack<int> stk;
    int cur_value = 1; // 현재 간식을 받아야 하는 번호

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // 배열 입력
    }

    for (int i = 0; i < n; i++) {
        // 현재 번호가 순서와 맞다면 바로 간식을 받음
        if (arr[i] == cur_value) {
            cur_value++;
        }
        else {
            // 스택이 비어있지 않으며 스택 맨 위가 순서에 맞는 경우 처리
            while (!stk.empty() && stk.top() == cur_value) {
                stk.pop();
                cur_value++;
            }
            // 현재 번호를 스택에 삽입
            stk.push(arr[i]);
        }
    }

    // 남은 스택 처리
    while (!stk.empty()) {
        if (stk.top() == cur_value) {
            stk.pop();
            cur_value++;
        }
        else {
            break; // 순서가 맞지 않으면 즉시 종료
        }
    }

    // 모든 간식을 순서대로 받을 수 있었는지 확인
    if (stk.empty())
        cout << "Nice\n";
    else
        cout << "Sad\n";

    return 0;
}
