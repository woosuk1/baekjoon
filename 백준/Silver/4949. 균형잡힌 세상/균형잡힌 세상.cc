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
	
	while (1) {
		string s;
		bool flag = true;
		stack<char> stk;


		getline(cin, s);

		// 마무리 조건
		if (s.size() == 1 && s[0] == '.') {
			break;
		}

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '[') {
				stk.push(s[i]);
			}
			else if (s[i] == ']') {
				if (!stk.empty()) {
					if (stk.top() != '[') {
						flag = false;
						break;
					}
					stk.pop();
				}
				else {
					flag = false;
					break;
				}
			}
			else if (s[i] == ')') {
				if (!stk.empty()) {
					if (stk.top() != '(') {
						flag = false;
						break;
					}
					stk.pop();
				}
				else {
					flag = false;
					break;
				}
			}

		}

		if (stk.empty() && flag) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}

	}

	return 0;
}