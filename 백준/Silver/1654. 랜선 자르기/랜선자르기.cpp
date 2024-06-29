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

ll n, k;
ll sum = 0;
ll arr[1000001] = { 0, };

ll binary_search(ll start, ll end, ll target) {
	ll mid, temp;
	while (start <= end) {
		temp = 0;
		mid = (start + end) / 2;
		for (int i = 0; i < k; i++) {
			temp += arr[i] / mid;
		}

		if (temp >= target)
			start = mid+1;
		else
			end = mid-1;
	}
	return end;
}

int main() {
	
	//binary search, upper bound

	cin >> k >> n; // 이미가지고 있는 개수 k, 필요한 랜선의 개수 n

	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	cout << binary_search(1, sum / n, n);

	return 0;

}