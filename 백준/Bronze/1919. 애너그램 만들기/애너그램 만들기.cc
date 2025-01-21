#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <vector>
#include <string>
#include <map>
#include <limits.h>
#include <queue>
#include <set>
#include <math.h>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string a;

	string b;

	cin >> a >> b;

	int count = 0;

	int a_save[26] = { 0 };
	int b_save[26] = { 0 };

	for (int i = 0; i < a.size(); i++) {
		a_save[a[i] - 'a']++;
	}

	for (int i = 0; i < b.size(); i++) {
		b_save[b[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		if (a_save[i] != b_save[i]) {
			count += abs(a_save[i] - b_save[i]);
		}
	}

	cout << count;

	return 0;
}
