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
using namespace std;

using ll = long long;

int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<string, double> tr;
    double cnt = 0;
    double ans;
    string temp;

    while (1) {
        getline(cin, temp);
        if (cin.eof()) {
            break;
        }
        if (tr.find(temp) != tr.end()) {
            tr[temp]++;
        }
        else
            tr[temp] = 1;
//        tr[temp]++;
        cnt++;
   }
    cout << fixed;
    cout.precision(4);

    for (auto i : tr) {
        ans = i.second / cnt * 100; //반올림하기
        cout << i.first << ' ' << ans << '\n';
    }

    return 0;
}