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

#define ll long long

pair<ll, ll> arr[1500002];
ll dp[1500002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
		cin >> arr[i].first >> arr[i].second;
    }

    for (int i = n; i >= 1; i--) {
        // i번째 일에 상담할 수 있는 경우
        if (i + arr[i].first <= n + 1) {
            dp[i] = max(dp[i + arr[i].first] + arr[i].second, dp[i + 1]);
        }
        else dp[i] = dp[i + 1];
    }

    cout << *max_element(dp, dp + n + 1);

    return 0;
}