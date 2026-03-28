#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <queue>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int arr[3];
	
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + 3);

	for (int i = 0; i < 3; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}