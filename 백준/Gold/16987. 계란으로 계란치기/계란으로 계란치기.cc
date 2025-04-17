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

pair<int, int> arr[10];
int n;
int mx = 0;
int cnt = 0; // 깨져있는 계란의 수

void backtrack(int idx) {
    // base
    // 가장 오른쪽에 위치한 계란일 때
    if (idx == n) {
        mx = max(mx, cnt);
        return;
    }
    // 계란으로 계란을 치게 되면 각 계란의 내구도는 상대 계란의 무게만큼 깎이게 된다.

    // 1. 가장 왼쪽의 계란을 든다.

    // 2. 손에 들고 있는 계란으로 깨지지 않은 다른 계란 중에서 하나를 친다.(암거나)
    // 단, 손에 든 계란이 깨졌거나 깨지지 않은 다른 계란이 없으면 치지 않고 넘어간다.
    // 이후 손에 든 계란을 원래 자리에 내려놓고 3번 과정을 진행한다.

    // 3. 가장 최근에 든 계란의 한 칸 오른쪽 계란을 손에 들고 2번 과정을 다시 진행한다. 
    // 단, 가장 최근에 든 계란이 가장 오른쪽에 위치한 계란일 경우 계란을 치는 과정을 종료한다.

    if (arr[idx].first <= 0 || cnt == n - 1) {
        backtrack(idx + 1);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (idx == i || arr[i].first <= 0) continue;
        arr[idx].first -= arr[i].second;
        arr[i].first -= arr[idx].second;
        if (arr[idx].first <= 0) cnt++;
        if (arr[i].first <= 0) cnt++;
        backtrack(idx + 1);
        if (arr[idx].first <= 0) cnt--;
        if (arr[i].first <= 0) cnt--;
        arr[idx].first += arr[i].second;
        arr[i].first += arr[idx].second;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 내구도와 무게 순으로 주어진다.

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    backtrack(0);
    cout << mx;

    return 0;
}