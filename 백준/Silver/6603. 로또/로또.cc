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

    while (1) {
        cin >> n;

        if (!n) {
            return 0;
        }

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> com(n);

        for (int i = 6; i < n; i++) {
            com[i] = 1;
        }
        
        do {
            for (int i = 0; i < n; i++) {
                if(!com[i])
                    cout << arr[i] << ' ';
            }
            cout << '\n';
        } while (next_permutation(com.begin(), com.end()));

        cout << '\n';
    }

    return 0;
}