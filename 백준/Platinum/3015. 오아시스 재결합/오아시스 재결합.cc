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
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    // 스택(first: 키, second: 같은 키를 가진 사람 수)
    stack<pair<int, int> > stk;

    cin >> n;

    int input, cnt_same = 0;

    long long int cnt_ans = 0;

    for (int i = 1; i <= n; i++) {
        cin >> input;

        // 같은 키를 갖는 사람
        cnt_same = 1;
        // stk.top 보다 키가 클 때 -> 각각의 저장된 수를 + 해주며 flush
        // stk.top.second에 저장된 수는 stk.top의 쌍의 수
        while (!stk.empty() && stk.top().first < input) {
            cnt_ans += stk.top().second;
            stk.pop();
        }

        // stack이 비어있지 않을 때
        if (!stk.empty()) {
            //
            if (stk.top().first == input) {
                // top과 같은 값을 지녔을 때, 같은 키를 가진 사람과 쌍을 지을 수 있음
                cnt_ans += stk.top().second;
                // 스택에 쌓여있을 때만 같은 쌍의 값을 업데이트해줌(cnt_same++)
                cnt_same = stk.top().second + 1;
                //stk.size()가 1 이상이면 stk에 자기보다 큰 값이 있으니, 쌍을 맺어줌
                if (stk.size() > 1)
                    cnt_ans++;

                // 같은 값 처리 후, 스택에 지금 값만 남긴다.(같은 쌍 몇개 인지 업데이트 된 지금 값)
                stk.pop();
            }
            // stk.top보다 작은 값을 지녔을 때(stk.top과만 쌍을 맺는다.)
            else {
                cnt_ans++;
            }
        }
        stk.push(make_pair(input, cnt_same));
    }

    cout << cnt_ans << " ";

    return 0;
}
