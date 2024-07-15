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
using namespace std;

using ll = long long;

int main() {

	string temp;

//	stack<char> stk; //초기화 이슈

	while (1) {
		getline(cin, temp);

		if (temp == ".")
			break;

		int flag = 0;

		stack<char> stk;

		for (int i = 0; i < temp.size(); i++) { //문자열 전체 순회하면서 (, [ 찾기
			if (temp[i] == ')' || temp[i] == ']') {
				if (stk.empty()) { //stack이 비었을 때,
					flag = 1;
					break;
				}
				else if ((stk.top() == '(' && temp[i] == ')') || stk.top() == '[' && temp[i] == ']') { // stk.top과 temp[i]
					stk.pop();
					continue;
				}
				else {
					flag = 1;
					break;
				}
				
			}
			else if (temp[i] == '(' || temp[i] == '[') {
				stk.push(temp[i]);
			}
		}

		if (!stk.empty())
			flag = 1;

		if (flag == 1)
			cout << "no\n";
		else
			cout << "yes\n";
	}

	return 0;
}