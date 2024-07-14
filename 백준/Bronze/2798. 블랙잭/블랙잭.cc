#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <deque>
#include <climits>
#include <set>
#include <stack>
using namespace std;

using ll = long long;

int main() {

    int n, m;


    int ans = 0;

    cin >> n >> m;

    vector<int> card_num(n);

    for (int i = 0; i < n; i++) {
        cin >> card_num[i];
    }

    for (int i = 0; i < n-2; i++) {
        for (int j = i + 1; j < n-1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (card_num[i] + card_num[j] + card_num[k] > m)
                    continue;
                else
                    ans = max(ans, card_num[i] + card_num[j] + card_num[k]);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}