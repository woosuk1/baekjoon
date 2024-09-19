#include<iostream>
#include <cstdio>
#include <algorithm> // for max
#include <vector>
#include <string>
#include <map>
#include <limits.h>

using namespace std;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// ioi 반복 횟수
	int n;
	cin >> n;
	//문자열 길이
	int s;
	
	// count는 연속된 ioi 횟수, answer은 출력값
	int count = 0, answer= 0;
	
//	bool flag = false;
	cin >> s;
	// 문자열 길이는 ioi
	string ioi;

	cin >> ioi;

	for (int i = 0; i < s; i++) {
		if (count == 0) {
			if (ioi[i] == 'I' && ioi[i + 1] == 'O' && ioi[i + 2] == 'I') {
				// 연속 횟수 증가 및 index 변경
				count++;
				i += 2;	//i++ 고려
//				flag = true;
				if (count >= n)
					answer++;
				continue;
			}
		}
		else {
//		else if (count != 0) {
			if (ioi[i] == 'O' && ioi[i + 1] == 'I') {
				count++;
				i++;
				if (count >= n)
					answer++;
			}
			else {
				i--;
				count = 0;
			}
		}
	}

	cout << answer;
}
