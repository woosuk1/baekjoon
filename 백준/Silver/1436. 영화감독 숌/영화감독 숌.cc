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

int arr[301][301];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a;
    int save = 666;
    string temp;

    cin >> a;

    int count = 0, flag = 0;

    while (flag == 0) {
        temp = to_string(save);
        for (int i = 0; i < temp.size() - 2; i++) {
            if (temp[i] == '6' && temp[i + 1] == '6' && temp[i + 2] == '6') {
                count++;
                if (count == a) {
                    flag = 1;
                    save--;
                }
                break;
            }
        }
        save++;
    }

    cout << save;

    return 0;
}