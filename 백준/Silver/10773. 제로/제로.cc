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

	int n, sum = 0;

	cin >> n;

	int save[100001] = { 0, };

	int count = 0;

	while (n--) {
		
		int temp;

		cin >> temp;

		if (temp == 0) {
			save[--count] = 0;
			continue;
		}

		save[count++] = temp;
	}

	for (int i = 0; i <= count; i++) {
		sum += save[i];
	}

	cout << sum;

	return 0;
}