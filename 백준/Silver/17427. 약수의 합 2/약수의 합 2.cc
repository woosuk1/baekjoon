#include<iostream>
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

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;

	long long answer = 0;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		answer += (n / i) * i;
	}

	cout << answer;

	return 0;
}