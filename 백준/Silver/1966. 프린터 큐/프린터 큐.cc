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

int main() {

	int t;

	cin >> t;

	int n, target;

	for (int test = 0;  test< t; test++) {
		queue<pair<int, int>> q;

		cin >> n >> target;

		vector<int> arr;

		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			arr.push_back(temp);
			q.push(make_pair(temp, i));
		}
		//내림차순 정렬
		sort(arr.rbegin(), arr.rend());
		//target 찾기

		int check = 0 , cnt = 0;
		while (!q.empty()) {
			if (arr[check] == q.front().first) { //남은 제일 큰 값과 queue의 중요도와 일치할 떄
				cnt++;
				if (q.front().second == target) { //target과 원래 인덱스가 일치할 때
					break;
				}
				q.pop();
				check++;
			}
			else {
				q.push(make_pair(q.front().first, q.front().second));
				q.pop();
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}