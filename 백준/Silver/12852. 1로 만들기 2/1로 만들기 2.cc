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

    int n;

    cin >> n;

    vector<pair<int, int> > arr(n + 1);

    arr[1] = {0, 0};
    // arr[2] = {1, 1};
    // arr[3] = {1, 1};

    for (int i = 2; i <= n; i++) {
        arr[i] = {arr[i - 1].first + 1, i - 1};
        if (i % 2 == 0 && arr[i / 2].first + 1 < arr[i].first) {
            arr[i] = {arr[i / 2].first + 1, i / 2};
        }
        if (i % 3 == 0 && arr[i / 3].first + 1 < arr[i].first) {
            arr[i] = {arr[i / 3].first + 1, i / 3};
        }
    }

    cout << arr[n].first << '\n';


    while (true) {
        cout << n << ' ';
        if (n == 1) break;
        n = arr[n].second;
    }

    return 0;
}
