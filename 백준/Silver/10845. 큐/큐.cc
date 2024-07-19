#include <iostream>
#include <queue>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	queue<int> q; // queue
	int n; // test case num
	string command; // command
	int num; // when push, save num in queue
	int result = 0; // result

	cin >> n;

	int i = 0;

	while (i < n) {

		cin >> command;

		if (command == "push") {
			int a;
			cin >> a;
			q.push(a);
		}
		else if (command == "pop") {
			if (q.size() == 0) {
				result = -1;
				cout << result << endl;
			}
			else {
				result = q.front();
				cout << result << endl;
				q.pop();
			}
		}
		else if (command == "size") {
			cout << q.size() << endl;
		}
		else if (command == "empty") {
			if (q.size() == 0) {
				result = 1;
				cout << result << endl;
			}
			else {
				result = 0;
				cout << result << endl;
			}
		}
		else if (command == "front") {
			if (q.size() == 0) {
				result = -1;
				cout << result << endl;
			}
			else {
				cout << q.front() << endl;
			}
		}
		else if (command == "back") {
			if (q.size() == 0) {
				result = -1;
				cout << result << endl;
			}
			else {
				cout << q.back() << endl;
			}
		}
		i++;
	}
}
