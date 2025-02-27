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
#define ll long long
using namespace std;

ll ans(ll a, ll b, ll c) {
    if (b == 1) return a % c;
    ll mod = ans(a, b / 2, c);
    // 2n으로 만들어주는 거임
    mod = mod * mod % c;
    if (b % 2 == 0) return mod;
    return mod * a % c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a, b, c;

    cin >> a >> b >> c;

    cout << ans(a, b, c);

    return 0;
}
