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

bool comp(string& a, string& b) {
    if (a.size() == b.size())
        return a < b;
    return a.size() < b.size();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    vector<string> word;

    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        word.push_back(temp);
    }


    sort(word.begin(), word.end(), comp);

    word.erase(unique(word.begin(), word.end()), word.end());

    for (int i = 0; i < word.size(); i++) {
        cout << word[i] << '\n';
    }



    return 0;
}