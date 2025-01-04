#include<iostream>
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

	int m;

	string sentence;

	while (cin >> m && m != 0) {

		cin.ignore();

		getline(cin, sentence);

//		for (int i = 0; i < sentence.size(); i++) {
	//		sentence[i] = tolower(sentence[i]);
		//}

		int start = 0, end = 0;
		int answer = 0; // 출력값

		map<char, int> mp;

		while(end < sentence.size()) {
			mp[sentence[end]]++;

			while (mp.size() > m) {

				mp[sentence[start]]--;
				
				if (mp[sentence[start]] == 0) {
					mp.erase(sentence[start]);
				}

				start++;
			}

			answer = max(answer, end - start + 1);
			end++;
		}

		cout << answer << '\n';
	}

	return 0;
}