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

	int a, b, v;

	int cur = 0, date = 1;

	cin >> a >> b >> v;

	if (a == v) {
		cout << 1;
		return 0;
	}

	// {a + (a-b) * date} = v
	
	date += (v - a) / (a - b);

	if ((v - a) % (a - b) != 0)
		date++;

	cout << date;
	
}