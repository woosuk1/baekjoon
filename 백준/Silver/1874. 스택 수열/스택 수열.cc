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

	int n, save = 0;

	cin >> n;

	stack<int> stk;
	vector<char> ans;

	int temp;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		// temp가 n과 같을 때를 고려해야 한다


		if (temp > save) {	//temp = save인 경우는 없다.
			for (int j = save + 1; j <= temp; j++) {
				stk.push(j);
				ans.push_back('+');
			}
			save = temp;
			stk.pop();
			ans.push_back('-');
		}
		else if (!stk.empty() && temp == stk.top()) { //입력값이 stack top과 같을 때
			stk.pop();
			ans.push_back('-');
		}
		else if (!stk.empty() && temp < stk.top()) { //입력값이 stack top보다 작을 때
			while (!stk.empty() && stk.top() >= temp) {
				stk.pop();
				ans.push_back('-');
			}
		}
		else {
			cout << "NO" << '\n';
			return 0;
		}

	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}


	return 0;
}