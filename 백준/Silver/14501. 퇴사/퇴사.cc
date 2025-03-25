#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <queue>
#include <set>
#include <math.h>
#include <stack>
#include <deque>

using namespace std;

int n;
pair<int,int> arr[16];
int answer = 0;
// 무슨 값이 있어야 할까? 현재 날짜, 상담비, 들어갈 수 있는가, 활성화된 날짜
void backtracking(int day, int value, pair<int,int> active, int prev) {
    if (day == n+1) {
        answer = max(answer, value);
        return;
    }

    //if (day + arr[day].first <= n)
    //    backtracking(day + 1, value + arr[day].second, arr[day]);

    //backtracking(day + 1, value, active);
    //돌아가고 있는 상태
    // 이전 값 저장?
    if (day - active.first - prev < 0 && active.first != 0) {
        backtracking(day + 1, value, active, prev);
    }
    // 돌아가지 않는 상태
    else {
        if(day + arr[day].first <= n+1)
            backtracking(day + 1, value + arr[day].second, arr[day], day);
        backtracking(day + 1, value, active, prev);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // n+1일째 되는 날 퇴사를 하기 위해서, 
    // 남은 n일 동안 최대한 많은 상담을 하려함

    // 하루에 하나씩 서로 다른 사람의 상담을 잡았다.

    // 각각의 상담은 
    // (완료하는데 걸리는 기간: T(i), 상담을 했을 때 받을 수 있는 금액: P(i))

    // 상담을 하는데 필요한 기간은 1일보다 클 수 있기에, 모든 상담을 할 수는 없다.

    // n+1에는 회사에 없기 때문에 (일자 + T(i))> N 은 못한다.
    // 최대 수익을 달성하는 프로그램 작성.

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    // 현재 상태를 저장할 수 있어야 할 것 같음.
    backtracking(1, 0, { 0,0 }, 0);

    cout << answer << '\n';

    return 0;
}