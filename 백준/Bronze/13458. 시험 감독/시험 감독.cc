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
#include <string.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, b, c;

    cin >> n;

    long long answer = n;

    vector<int> arr(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> b >> c;

    for (int i = 0; i < n; i++) {
        arr[i] -= b;
        if (arr[i] <= 0)
            continue;
        answer += arr[i] / c;
        if (arr[i] % c != 0)
            answer++;
    }

    cout << answer << '\n';

    return 0;
}
