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

    cin >> n;

    deque<int> q;

    while (n--) {
        string s;
        cin >> s;

        if (s == "push_back") {
            int temp;
            cin >> temp;
            q.push_back(temp);
        } else if (s == "push_front") {
            int temp;
            cin >> temp;
            q.push_front(temp);
        } else if (s == "pop_front") {
            if (!q.empty()) {
                cout << q.front() << "\n";
                q.pop_front();
            } else {
                cout << "-1\n";
            }
        } else if (s == "pop_back") {
            if (!q.empty()) {
                cout << q.back() << "\n";
                q.pop_back();
            } else {
                cout << "-1\n";
            }
        } else if (s == "size") {
            cout << q.size() << "\n";
        } else if (s == "empty") {
            cout << q.empty() << "\n";
        } else if (s == "front") {
            if (!q.empty()) {
                cout << q.front() << "\n";
            } else {
                cout << "-1\n";
            }
        } else if (s == "back") {
            if (!q.empty()) {
                cout << q.back() << "\n";
            } else {
                cout << "-1\n";
            }
        }
    }

    return 0;
}
