#include<iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <queue>
#include <set>
#include <cmath>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, v;

    cin >> n;

    vector<int> arr(201);

    int temp;

    for (int i = 0; i < n; i++) {
        cin >> temp;

        arr[temp + 100]++;
    }

    cin >> v;

    cout << arr[v + 100] << '\n';

    return 0;
}
