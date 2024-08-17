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
#include <sstream>
using namespace std;

using ll = long long;

void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}

int arr[100010];
bool visited[100010];
int n, k;

void bfs(int start) {
	queue<int> que;
	que.push(start);
	visited[start] = true;
	
	while (!que.empty()) {
		int x = que.front();
		que.pop();
		
		if (!visited[x-1] && x>0) {
			que.push(x - 1);
			arr[x - 1] = arr[x] + 1;
			visited[x - 1] = true;
		}
		if (!visited[x+1] && x<100000) {
			que.push(x +1);
			arr[x + 1] = arr[x] + 1;
			visited[x +1] = true;
		}
		if (!visited[x * 2] && x <= 50000) {
			que.push(x * 2);
			arr[x * 2] = arr[x] + 1;
			visited[x * 2] = true;
		}

		if (visited[k])
			break;
	}
}


int main() {

	init();
	
	cin >> n >> k;

	arr[n] = 0;

	bfs(n);
	
	cout << arr[k];

	return 0;
}