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

vector<int> arr;
int ans[30];
int visited[30];

int n,m;

void dfs(int idx) {
	if (idx == m) {
		for (int i = 0; i < m; i++) {
			cout << ans[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i] && ans[idx-1] < arr[i]) {
			visited[i] = 1;
			ans[idx] = arr[i];
			dfs(idx + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;


	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	
	sort(arr.begin(), arr.end());

	dfs(0);
	
	return 0;
}