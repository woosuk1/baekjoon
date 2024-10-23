#include<iostream>
#include <cstdio>
#include <algorithm> // for max
#include <vector>
#include <string>
#include <map>
#include <limits.h>
#include <queue>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;
	
	priority_queue<int> pq;

	int temp;

	while (n--) {
		cin >> temp;


		if (temp == 0) {
			if (pq.size() == 0) {
				cout << 0 << '\n';
				continue;
			}
			cout << pq.top() << '\n';
			pq.pop();
		}
		else {
			pq.push(temp);
		}
	}

    return 0;
}
