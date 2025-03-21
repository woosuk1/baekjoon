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

int n, s, cnt = 0;
int arr[30] = { 0 };

void dfs(int cur, int total) {
    // base position이 뭘까? a의 합이 s가 되는 순간
    if (cur == n) {
        if (total == s) {
            cnt++;
        }
        return;
    }
     dfs(cur + 1, total);
     dfs(cur + 1, total + arr[cur]);
}

// 원소가 n개인 집합해서 부분집합의 갯수는 2^n

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // n개의 정수로 이루어져 있으며, 
    // s는 부분수열 중에서 그 수열의 원소를 다 더한 값(target)
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // 초기값은 0
    dfs(0,0);
    if (s == 0) cnt--;
    cout << cnt;

    return 0;
}