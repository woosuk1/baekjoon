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
#include <stack>
#include <tuple>
using namespace std;

using ll = long long;

int main() {
	
	int n, count =1;

	cin >> n;

	vector<pair<int, int>> ha; //이름, 등수 쌍으로 입력

	for (int i = 0; i < n; i++) {
		int temp1, temp2;

		cin >> temp1 >> temp2;

		ha.push_back(make_pair(temp1, temp2));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (ha[i].first < ha[j].first && ha[i].second < ha[j].second)
				count++;
		}
		cout << count << ' ';
		count = 1;
	}

	return 0;
}