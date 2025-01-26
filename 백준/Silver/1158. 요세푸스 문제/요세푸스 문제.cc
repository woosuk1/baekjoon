#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, tmp;

	cin >> n >> m;

	queue<int> q;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}


	cout << '<';
	
	while (q.size() > 1) {
		for (int i = 0; i < m - 1; i++) {
			tmp = q.front();
			q.push(tmp);
			q.pop();
		}

		tmp = q.front();
		cout << tmp << ", ";
		q.pop();
	}

	tmp = q.front();

	cout << tmp << ">\n";

	return 0;
}