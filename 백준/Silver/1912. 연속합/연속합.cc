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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    int answer = 0;

    cin >> n;

    vector<int> arr(n);
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    d[0] = arr[0];
    answer = arr[0];
    for (int i = 1; i < n; i++) {
        d[i] = max(0, d[i - 1]) + arr[i];
        answer = max(d[i], answer);
    }

    cout << answer << '\n';

    return 0;
}
