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

    int n;


    cin >> n;


    vector<int> arr(n + 1, 999999999);


    for (int i = 1; i <= n; i++) {
        int temp;
        temp = i;
        int save = i;
        while (save > 0) {

            temp += save % 10;

            save /= 10;

        }

        if (temp == n) {
            cout << i;
            return 0;
        }

    }

    if (arr[n] == 999999999)
        cout << 0;
    
    
}