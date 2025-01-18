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
    
    // 저장할 배열 : 2는 성별, 6은 학년
    int arr[2][7] = {0};

    int n, k, ans = 0;

    // n은 참여 학생 수, k는 한 방에 최대 인원 수
    cin >> n >> k;

    int temp1, temp2;

    for (int i = 0; i < n; i++) {
        cin >> temp1 >> temp2;

        arr[temp1][temp2]++;
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= 6; j++) {
            if (arr[i][j] % k == 0)
                ans += arr[i][j] / k;
            else
                ans += arr[i][j] / k + 1;
        }
    }

    cout << ans;

    return 0;
}
