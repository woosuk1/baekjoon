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

// 2개 : 1
// 3개 : 7
// 4개 : 4
// 5개 : 2,3,5
// 6개 : 0,6,9
// 7개 : 8

/*
	9*6 다해서 경우의 수 만들어보기
*/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;

	// 기본으로 4개 빠진다.
	cin >> n;

	map<int, int> mp;

	mp[0] = 6;
	mp[1] = 2;
	mp[2] = 5;
	mp[3] = 5;
	mp[4] = 4;
	mp[5] = 5;
	mp[6] = 6;
	mp[7] = 3;
	mp[8] = 7;
	mp[9] = 6;

	map<int, int> fir_num;
	map<int, int> sec_num;
	map<int, int> thi_num;

	int count = 0; // 숫자 세기용
	int answer = 0; // 몇개가 충족하냐?

	// 수식 반복문
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			string a = to_string(i);
			string b = to_string(j);
			if (a != "0")
				b = a + b;

			fir_num.insert({stoi(b), mp[i] + mp[j]});
			sec_num.insert({stoi(b), mp[i] + mp[j]});
			thi_num.insert({stoi(b), mp[i] + mp[j]});
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			for (int k = 0; k < 100; k++) {
				// 수식이 성립할 때.
				if (i + j == k) {
					if (n - 4 == (fir_num[i] + sec_num[j] + thi_num[k])) {
						if (i < 10) {
							cout << '0' << i << '+';
						}
						else {
							cout << i << '+';
						}
						if (j < 10) {
							cout << '0' << j << '=';
						}
						else {
							cout << j << '=';
						}
						if (k < 10) {
							cout << '0' << k;
						}
						else {
							cout << k;
						}
						return 0;
					}
				}
			}
		}
	}

	cout << "impossible";

	return 0;

}