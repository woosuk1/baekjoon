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

	int score;

	cin >> score;

	if (score >= 90 && score <= 100) {
		cout << 'A';
	}
	else if (score >= 80) {
		cout << 'B';
	}
	else if (score >= 70) {
		cout << 'C';
	}
	else if (score >= 60) {
		cout << 'D';
	}
	else {
		cout << 'F';
	}

	return 0;
}