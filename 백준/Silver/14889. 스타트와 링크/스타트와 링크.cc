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

    // 축구를 하기 위해 모인 사람은 총 n명, n은 짝수다.
    // n/2명으로 이루어진 2팀으로 나눈다.

    // 사람에게 번호를 1부터 n까지로 배정.

    // 능력치 S(ij)는 i번 사람과 j번 사람이 같은 팀에 속했을 때,
    // 팀에 더해지는 능력치이다.
    // 팀의 능력치는 팀에 속한 모든 쌍의 능력치 S(ij)의 합이다.

    // S(ij), S(ji)는 다를 수 있다. 
    // i,j가 같은 팀에 속했을 때 더해지는 능력치는 S(ij), S(ji)다.

    // 조합으로 구하자

    int n, ans = INT_MAX;

    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    // 두팀으로 나누는 10개를 고르는 조합 사용
    vector<int> for_combi(n);
    
    for (int i = n/2; i < n; i++) {
        for_combi[i] = 1;
    }

    do {
        vector<int> temp_arr;
        vector<int> temp_arr2;
        int temp1 = 0, temp2 = 0;
        for (int i = 0; i < for_combi.size(); i++) {
            if (for_combi[i] == 0) {
                temp_arr.push_back(i);
            }
            else {
                temp_arr2.push_back(i);
            }
        }

        // 이중 반복문으로 능력치 계산
        for (int i = 0; i < n/2-1; i++) {
            for (int j = i+1; j < n/2; j++) {
                temp1 += arr[temp_arr[i]][temp_arr[j]] + arr[temp_arr[j]][temp_arr[i]];
                temp2 += arr[temp_arr2[i]][temp_arr2[j]] + arr[temp_arr2[j]][temp_arr2[i]];
            }
        }

        ans = min(ans, abs(temp2 - temp1));
        
    } while (next_permutation(for_combi.begin(), for_combi.end()));

    cout << ans << '\n';

    return 0;
}