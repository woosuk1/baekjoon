#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#define SIZE 8

using namespace std;

int arr[SIZE+1], visited[SIZE + 1], n, m;

void dfs(int cnt,int idx) {
	if (cnt == m) {
		for (int i = 0; i < n; i++) {
			if(visited[i])
				cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i < n; i++) {
		if (visited[i]) continue;
		visited[i] = 1;
		dfs(cnt+1,i+1);
		visited[i] = 0;
	}
}

int main() {
	
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
		visited[i] = false;
	}

	dfs(0,0);
	
	return 0;
}