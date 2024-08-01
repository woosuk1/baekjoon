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

vector<int> arr[100001];
bool visited[100001];
vector<pair<int, int>> save;

void dfs(int start) {
	visited[start] = true;

	for (int i = 0; i < arr[start].size(); i++) {
		if (!visited[arr[start][i]]) {
			save.push_back(make_pair(arr[start][i], start));
			dfs(arr[start][i]);
		}
	}
}


int main() {

	int n;
	int temp1, temp2;
	
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		cin >> temp1 >> temp2;

		arr[temp1].push_back(temp2);
		arr[temp2].push_back(temp1);
	}

	dfs(1);

	sort(save.begin(), save.end());

	for (int i = 0; i < n-1; i++) {
		cout << save[i].second << '\n';
	}

	return 0;
}