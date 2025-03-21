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




    // c개의 문자가 주어졌을 때, 가능성 있는 암호들을 모두 구하는 프로그램

    int l, c;

    cin >> l >> c;

    vector<char> arr(c);
    
    for (int i = 0; i < c; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<int> com(c);
    
    for (int i = l; i < c; i++) {
        com[i] = 1;
    }

    // 암호는 서로 다른 L개의 알파벳 소문자들로 구성
    // 최소 한 개의 모음, 최소 2개의 자음으로 구성
    // 오름차순으로 배열된 암호들
    do {
        string temp = "";
        bool flag = true;
        int cnt_aeiou = 0;
        int cnt_else = 0;
        for (int i = 0; i < c; i++) {
            if (com[i] == 0) {
                if (temp.size() > 0 && temp[temp.size()-1] > arr[i]) {
                    flag = false;
                    break;
                }
                temp += arr[i];
                if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
                    cnt_aeiou++;
                }
                else {
                    cnt_else++;
                }
            }
        }
        if (!flag)
            continue;

        if (cnt_aeiou < 1 || cnt_else < 2)
            continue;

        cout << temp << '\n';
       
    } while (next_permutation(com.begin(), com.end()));

    return 0;
}