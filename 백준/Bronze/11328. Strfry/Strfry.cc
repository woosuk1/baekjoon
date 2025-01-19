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

    int n;

    cin >> n;

    string temp;
    string temp2;

    while (n--) {
        bool flag = true;

        map<char, int> first_string;
        map<char, int> second_string;

        cin >> temp;

        for (char i: temp) {
            first_string[i]++;
        }

        cin >> temp2;

        for (char i: temp2) {
            second_string[i]++;
        }

        if (temp.size() == temp2.size()) {
            for (char i: temp) {
                if (first_string[i] != second_string[i]) {
                    flag = false;
                    cout << "Impossible\n";
                    break;
                }
            }
            if (flag) {
                cout << "Possible\n";
            }
        } else {
            cout << "Impossible" << "\n";
        }
    }

    return 0;
}
