#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <vector>
#include <string>
#include <map>
#include <limits.h>
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
	
	int n, l;

	cin >> n >> l;

	deque<pair<int, int>> dq;

	int input;

	for (int i = 0; i < n; i++) {
		cin >> input;

		// input값보다 큰 앞에 값들 제거해주기
		while (!dq.empty() && dq.back().first > input) {
			dq.pop_back();
		}

		// 지워주고 뒤에 붙여주기
		dq.push_back(make_pair(input, i));

		// 인덱스 값이 슬라이딩 윈도우를 넘은 버릴 값일 때
		if (dq.front().second <= i - l) {
			dq.pop_front();
		}

		cout << dq.front().first << ' ';
	}

	return 0;
}