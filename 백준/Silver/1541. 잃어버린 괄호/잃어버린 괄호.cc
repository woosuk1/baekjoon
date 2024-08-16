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
#include <unordered_map>
#include <sstream>
using namespace std;

using ll = long long;

void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int main() {

	init();
	
	int ans = 0;

	string sejun;

	cin >> sejun;

	int save = 0;
	// 순전히 첫 '-'를 만나기 전까지 활성 되지 않은 것.
	bool flag = false;

	string temp ="";

	for (int i = 0; i < sejun.size(); i++) {
		if (flag == true && i == sejun.size() - 1) {
			temp += sejun[i];
			save += stoi(temp);
			ans -= save;
			break;
		}
		else if (i == sejun.size() - 1) {
			temp += sejun[i];
			save += stoi(temp);
			ans += save;
			break;
		}
		if (sejun[i] == '-' && flag == true) {
			save += stoi(temp);
			ans -= save;
			save = 0;
			temp = "";
		}
		else if (sejun[i] == '-' && flag == false) {
			save += stoi(temp);
			ans += save;
			temp = "";
			save = 0;
			flag = true;
		}
		else if (sejun[i] == '+') {
			save += stoi(temp);
			temp = "";
		}
		else {
			temp += sejun[i];
		}
		/*
		if (i == sejun.size() - 1 && flag == true)
			ans -= save;
		else if (i == sejun.size() - 1)
			ans += save;
		*/
	}
	
	cout << ans;

	return 0;
}