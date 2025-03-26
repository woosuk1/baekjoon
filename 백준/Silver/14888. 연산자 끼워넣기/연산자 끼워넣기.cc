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

    // n개의 수로 이루어진 수열이 주어진다.
    // 수와 수 사이에 끼워넣을 수 있는 n-1개의 연산자가 주어진다.
    // 연산자는 +, - , x, ÷.

    // 수와 수 사이에 연산자를 하나씩 넣어서, 수식을 하나 만들 수 있다.
    // 이때, 주어진 수의 순서를 바꾸면 안됨

    // set + next_permutation으로 조합의 수를 가져갈 거임

    int n;

    int max_ans = INT_MIN, min_ans = INT_MAX;

    cin >> n;

    vector<int> arr(n);
    vector<int> cal_arr(n-1);
    set<vector<int>> unique_arr;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int index = 0;

    for (int i = 0; i < 4; i++) {
        int num;
        cin >> num;
        // 연산자 저장하기 0: 덧셈, 1:뺄셈, 2:곱셈, 3:나눗셈       
        while (num--) {
            cal_arr[index] = i;
            index++;
        }
    }

    do {
        unique_arr.insert(cal_arr);
    } while (next_permutation(cal_arr.begin(), cal_arr.end()));


    for (auto s : unique_arr) {
        int init = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            // 연산자 별로 조건
            if (s[i - 1] == 0) {
                init += arr[i];
            }
            else if (s[i - 1] == 1) {
                init -= arr[i];
            }
            else if (s[i - 1] == 2) {
                init *= arr[i];
            }
            else if (s[i - 1] == 3) {
                init /= arr[i];
            }
        }

        max_ans = max(max_ans, init);
        min_ans = min(min_ans, init);
    }

    cout << max_ans << '\n' << min_ans << '\n';

    return 0;
}