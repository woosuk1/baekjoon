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
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;

	cin >> t;

	string sentence;
	// 배열이 담겨있는 문자열
	string input_arr;

	while (t--) {
		cin >> sentence;

		bool is_pop_front = true;
		// deque 사이즈가 0 이하 일 때 플래그
		bool flag = true;

		int dq_size;
		
		deque<int> dq;

		// 사이즈 입력 받기
		cin >> dq_size;

		// 배열 문자열 입력 받기
		cin >> input_arr;

		string temp;
		// 파싱하기([랑 ] 빼고)
		// , 만나기 전까지 temp에 쌓기
		// , 만나면 dq.push, count
		// 마무리 조건은 i = input_arr -2 일 때 temp값 push 해주기
		if (dq_size != 0) {
			for (int i = 1; i < input_arr.size() - 1; i++) {

				if (input_arr[i] == ',') {
					dq.push_back(stoi(temp));
					temp = "";
				}
				else {
					temp += input_arr[i];
				}

				if (i == input_arr.size() - 2) {
					dq.push_back(stoi(temp));
				}
			}
		}

		for (int i = 0; i < sentence.size(); i++) {
			if (sentence[i] == 'R') {
				is_pop_front = !is_pop_front;
				continue;
			}

			if (dq.empty()) {
				flag = false;
				break;
			}

			if (is_pop_front) {
				dq.pop_front();
			}
			else {
				dq.pop_back();
			}
		}

		if (!flag) {
			cout << "error" << '\n';
		}
		else {
			cout << '[';
			if (is_pop_front) {
				while (!dq.empty()) {
					if (dq.size() != 1) {
						cout << dq.front() << ',';
					}
					else {
						cout << dq.front();
					}
					dq.pop_front();
				}
			}
			else {
				while (!dq.empty()) {
					if (dq.size() != 1) {
						cout << dq.back() << ',';
					}
					else {
						cout << dq.back();
					}
					dq.pop_back();
				}
			}
			cout << "]\n";
		}
	}

	return 0;
}
