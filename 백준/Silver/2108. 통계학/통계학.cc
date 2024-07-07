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

bool comp(pair<int, int>& a, pair<int, int>& b) {
	return a.second > b.second;
}

int main() {

	int n; //n은 홀수다

//	float sum = 0;
	double sum = 0;
	cin >> n;

	if (n == 1) {
		cin >> n;
		cout << n << '\n' << n << '\n' << n << '\n' << 0;
		return 0;
	}

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	
	sum /= n;
	
	sum = floor(sum + 0.5);

	printf("%d\n", (int)sum);
	
	sort(arr.begin(), arr.end());

	// 중앙값

	cout << arr[n / 2] << '\n';

	//map을 이용한 최빈값
	map<int, int> mp;

	for (int i = 0; i < n; i++) {
		mp[arr[i]]++;
	}
	
	vector<pair<int, int>> vec(mp.begin(), mp.end()); //복사 생성자

	sort(vec.begin(), vec.end(), comp);


	if (vec[0].second == vec[1].second)
		cout << vec[1].first << '\n';
	else
		cout << vec[0].first << '\n';

	/*
	for (auto v : vec) {
		if (count == 0) {
			temp = v.second;
			ans = v.first;
		}
		if (count == 1) {
			temp2 = v.second;

			if (temp == temp2) {
				ans = v.first;
			}
			break;
		}

		count++;
	}
	*/

	cout << abs(arr[n-1] - arr[0]) << '\n';


	return 0;
}