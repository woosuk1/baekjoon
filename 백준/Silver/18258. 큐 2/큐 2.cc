#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
/*
int solution(int k, int m) {
	int count = 0;
	while (k > 1) {
		if (k % m == 0)
			k /= m;
		else
			k -= 1;
		count++;
	}
	return count;
}
*/
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;

	cin >> n; //명령의 수

	queue<int> que;

	for (int i = 0; i < n; i++) {
		string temp = "";

		cin >> temp;

		if (temp == "push") {
			int a;
			cin >> a;
			que.push(a);
		}
		else if (temp == "pop") {
			if (que.empty())
				cout << "-1" << "\n";
			else {
				cout << que.front() << "\n";
				que.pop();
			}
		}
		else if (temp == "size") {
			cout << que.size() << "\n";
		}
		else if (temp == "empty") {
			if (que.empty())
				cout << '1' << "\n";
			else
				cout << '0' << "\n";
		}
		else if (temp == "front") {
			if (!que.empty())
				cout << que.front() << "\n";
			else
				cout << "-1" << "\n";
		}
		else if (temp == "back") {
			if (!que.empty())
				cout << que.back() << "\n";
			else
				cout << "-1" << "\n";
		}
	}

//	cout << solution(k, m) << endl;
	return 0;
}