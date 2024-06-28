#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, Max = 0;

	cin >> n;

	double sum = 0;
	vector<double> arr;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		
		arr.push_back(temp);

		Max = max(temp, Max);
	}

	for (int i = 0; i < n; i++) {
		arr[i] = arr[i] / Max * 100;
		sum += arr[i];
	}

	printf("%.2f", sum / n);
}