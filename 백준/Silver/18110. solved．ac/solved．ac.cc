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
using namespace std;

using ll = long long;

void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}


int main() {

	init();

	int n,era_per, count =0, ans;
	double avg = 0;
	cin >> n;

	if (n == 0) {
		cout << 0;
		return 0;
	}


	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	
	double era_per_chk = (double) n * 15 / 100;

	era_per = floor(era_per_chk + 0.5);
	
	// 0~era_per -1 , n-era_per n-1 --> era_per ~ (n-era_per -1)

	for (int i = era_per; i < n - era_per; i++) {
		avg += arr[i];
		count++;
	}


	avg = floor((avg / count) + 0.5);

	ans = avg;

	cout << ans;

	return 0;
}