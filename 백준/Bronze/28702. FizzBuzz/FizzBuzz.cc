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
using namespace std;

using ll = long long;

void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}


int main() {

	init();

	// 3  6  9  12  15  18  21  24  27  30
	//   5    10    15    20      25    30
	// 1 2 fizz 4 buzz fizz 7 8 fizz buzz 11 fizz 13 14 fizzbuzz

	//첫번째 숫자 / fizz /  buzz / fizzbuzz

	string a, b, c;

	cin >> a >> b >> c;

	char a1, b1, c1;

	a1 = a[0];
	b1 = b[0];
	c1 = c[0];

	if(a1 >= '1' && a1 <= '9'){
		int num = stoi(a); //문자열 변환
		switch (num % 15) { //나머지 연산한 값
		case 1:
			cout << num + 3;
			break;
		case 2:
			cout << "Buzz";
			break;
		case 4:
			cout << num + 3;
			break;
		case 7:
			cout << "Buzz";
			break;
		case 8:
			cout << num + 3;
			break;
		case 11:
			cout << num + 3;
			break;
		case 13:
			cout << num + 3;
			break;
		case 14:
			cout << num + 3;
			break;
		}
	}
	else if (a1 == 'F') {
		if (a.size() > 5) {
			cout << "Fizz";
		}
		else if(b1>='1' && b1 <= '9'){
			int num = stoi(b);
			switch (num % 15) {
			case 4:
				cout << "Fizz";
				break;
			case 7:
				cout << "Fizz";
				break;
			case 13:
				cout << "FizzBuzz";
				break;
			}
		}
		else {
			cout << "Fizz";
		}
	}
	else {	// buzz 일 떄
		if (b1 == 'F') {
			cout << stoi(c) + 1;
		}
		else
			cout << stoi(b) + 2;
	}

	return 0;
}