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

bool visited[101];
vector<int> arr[101];
int cnt[101] = { 0 };

int bfs(int start) {
	int save = 0;
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < arr[x].size(); i++) {
			int y = arr[x][i];
			if (!visited[y]) {
				q.push(y);
				visited[y]= true;
				cnt[y] = cnt[x] + 1;
				save+= cnt[y];
	//			cout << "y: "<< y << "cnt[y]: " << cnt[y] << '\n';
			}
		}
	}
	return save;
}

int main() {

	init();
	
	//유저의 수, 친구 관계의 수
	int n, m;

	int min_per = 5001, ans = 101;

	cin >> n >> m;

	int temp1, temp2;

	for (int i = 0; i < m; i++) {
		cin >> temp1 >> temp2;

		arr[temp1].push_back(temp2);
		arr[temp2].push_back(temp1);
	}

	for (int i = 1; i <= n; i++) {
//		cout << i << '\n';
		int temp = bfs(i);
		if (min_per > temp) {
			min_per = temp;
			ans = i;
		}
//		min_per = min(min_per , bfs(i));
		memset(visited, false, sizeof(visited));
		memset(cnt, false, sizeof(cnt));
//		cout << '\n';
	}

	cout << ans;

	return 0;
}