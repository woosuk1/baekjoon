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

    // 8개의 톱니를 가진 톱니바퀴 4개가 일렬로 놓여져 있다.

    // 톱니바퀴를 총 k번 회전시키려 한다. 회전 방향은 시계, 반시계

    // input.
    // 1,2,3,4 줄에 n번 톱니바퀴의 상태가 주어진다. n은 0, s는 1로 나타난다.
    // 5줄에는 회전 횟수 k가 주어진다.
    // 다음 k개 줄에는 회전시킨 방법이 순서대로 주어진다. 시계방향은 1, 반시계 -1

    // output.
    /*
    *   총 K번 회전시킨 이후에 네 톱니바퀴의 점수의 합을 출력
        1번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 1점
        2번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 2점
        3번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 4점
        4번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 8점

        deque index = 0 출력
    */

    // deque로 하면 좋을 것 같은데?? deque[2] , deque[6]

    deque<char> dq1;
    deque<char> dq2;
    deque<char> dq3;
    deque<char> dq4;

    int answer = 0;

    string temp;

    cin >> temp;

    for (int i = 0; i < 8; i++) {
        dq1.push_back(temp[i]);
    }

    cin >> temp;

    for (int i = 0; i < 8; i++) {
        dq2.push_back(temp[i]);
    }

    cin >> temp;

    for (int i = 0; i < 8; i++) {
        dq3.push_back(temp[i]);
    }

    cin >> temp;

    for (int i = 0; i < 8; i++) {
        dq4.push_back(temp[i]);
    }

    int k;

    cin >> k;

    // 회전시키려면, 회전시킬 톱니바퀴, 회전시킬 방향을 결정해야 한다.

    // 회전할 때, 서로 맞닿은 극에 따라, 옆에 있는 톱니바퀴를 회전시킬 수도 있다.

    // A를 회전 시, (회전 전에)B와 서로 맞닿은 톱니의 극이 다르다면, B는 A가 회전한 방향과 반대방향으로 회전한다.
    
    // 1번은 dq1[2]만 고려
    // 2,3번 dq2[2], dq[6] 고려
    // 4번 dq[6] 고려

    // 1,2,3,4 줄에 n번 톱니바퀴의 상태가 주어진다. n은 0, s는 1로 나타난다.

    while (k--) {
        int num, dir;
        // 톱니바퀴 번호, 방향
        cin >> num >> dir;

        vector<pair<int,int> > to_cur;

        // num이 1일 경우
        if (num == 1) {
            to_cur.push_back({ 1,dir });
            // 2번과 반대인지?
            if (dq1[2] != dq2[6]) {
                to_cur.push_back({ 2, -dir });
                if (dq2[2] != dq3[6]) {
                    to_cur.push_back({ 3, dir });
                    if (dq3[2] != dq4[6]) {
                        to_cur.push_back({ 4, -dir });
                    }
                }
            }
        }
        else if (num == 2) {
            to_cur.push_back({ 2,dir });
            if (dq1[2] != dq2[6]) {
                to_cur.push_back({ 1,-dir });
            }
            if (dq2[2] != dq3[6]) {
                to_cur.push_back({ 3,-dir });
                if (dq3[2] != dq4[6]) {
                    to_cur.push_back({ 4,dir });
                }
            }
        }
        else if (num == 3) {
            to_cur.push_back({ 3,dir });
            if (dq3[2] != dq4[6]) {
                to_cur.push_back({ 4,-dir });
            }
            if (dq2[2] != dq3[6]) {
                to_cur.push_back({ 2,-dir });
                if (dq2[6] != dq1[2]) {
                    to_cur.push_back({ 1,dir });
                }
            }
        }
        else {
            to_cur.push_back({ 4,dir });
            // 2번과 반대인지?
            if (dq3[2] != dq4[6]) {
                to_cur.push_back({ 3, -dir });
                if (dq2[2] != dq3[6]) {
                    to_cur.push_back({ 2, dir });
                    if (dq1[2] != dq2[6]) {
                        to_cur.push_back({ 1, -dir });
                    }
                }
            }
        }
        
        for (int i = 0; i < to_cur.size(); i++) {
            if (to_cur[i].first == 1) {
                if (to_cur[i].second == 1) {
                    dq1.push_front(dq1.back());
                    dq1.pop_back();
                }
                else {
                    dq1.push_back(dq1.front());
                    dq1.pop_front();
                }
            }
            else if (to_cur[i].first == 2) {
                if (to_cur[i].second == 1) {
                    dq2.push_front(dq2.back());
                    dq2.pop_back();
                }
                else {
                    dq2.push_back(dq2.front());
                    dq2.pop_front();
                }
            }
            else if (to_cur[i].first == 3) {
                if (to_cur[i].second == 1) {
                    dq3.push_front(dq3.back());
                    dq3.pop_back();
                }
                else {
                    dq3.push_back(dq3.front());
                    dq3.pop_front();
                }
            }
            else if (to_cur[i].first == 4) {
                if (to_cur[i].second == 1) {
                    dq4.push_front(dq4.back());
                    dq4.pop_back();
                }
                else {
                    dq4.push_back(dq4.front());
                    dq4.pop_front();
                }
            }
        }
    }

    // 문자로 분기해주기
    // s극
    if (dq1[0] == '1') {
        answer++;
    }

    if (dq2[0] == '1') {
        answer+=2;
    }
    if (dq3[0] == '1') {
        answer+=4;
    }
    if (dq4[0] == '1') {
        answer+=8;
    }

    cout << answer << '\n';

    return 0;
}