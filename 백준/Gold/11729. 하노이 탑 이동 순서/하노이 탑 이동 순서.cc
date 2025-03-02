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

void cal(int n, int start, int mid, int end) {
    if (n == 1) {
        cout << start << ' ' << end << '\n';
        return;
    }

    cal(n - 1, start, end, mid);

    // start의 제일 아래 값을 end로 옮겨주는 과정
    cout << start << ' ' << end << '\n';

    cal(n - 1, mid, start, end);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, count = 0;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        count = 2 * count + 1;
    }

    cout << count << '\n';

    cal(n, 1, 2, 3);

    return 0;
}
