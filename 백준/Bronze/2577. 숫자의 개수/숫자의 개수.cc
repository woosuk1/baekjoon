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

	int a, b, c;

	int result = 1;

	int ans[11] = { 0 };

	cin >> a >> b >> c;

	result = a * b * c;

	while(result > 0){
		ans[result % 10]++;

		result /= 10;
	}

	for (int i = 0; i < 10; i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}
