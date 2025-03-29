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

int t, a, b;
int grades[100001][6] = { 0, }; // grade 저장용
int maxval = 0, minidx = 6; //횟수, 그레이드


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<string> save(5);

	for (int i = 0; i < 5; i++) {
		cin >> save[i];
	}

	for (int i = 0; i <15; i++) {
		for (int j = 0; j < 5; j++) {
			if (save[j].size() > i)
				cout << save[j][i];
		}
	}

	return 0;
}