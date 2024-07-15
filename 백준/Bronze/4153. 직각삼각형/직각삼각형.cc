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

	int arr[3] = { 0, };
	while (1) {

		for (int i = 0; i < 3; i++) {
			cin >> arr[i];
		}

		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
			break;

		sort(arr, arr + 3);

		if ((arr[0] * arr[0]) + (arr[1] * arr[1]) == arr[2] * arr[2])
			cout << "right\n";
		else
			cout << "wrong\n";
		
	}
	
	return 0;
}