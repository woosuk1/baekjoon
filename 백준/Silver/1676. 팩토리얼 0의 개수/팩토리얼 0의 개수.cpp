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
using namespace std;

using ll = long long;



int main() {
	
	int n, count =0;

	cin >> n;

	int temp;

	for (int i = 2; i <= n; i++) {
		temp = i;
		while (temp / 5 > 0 && temp % 5 == 0) {
			count++;
			temp /= 5;
		}
	}

	cout << count;

	return 0;
}